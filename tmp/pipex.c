# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		cmd_num;
	int		pipe_num;
	int		fd1;
	int		fd2;
	char	**paths;
	int		**pipes;
	char	***newargvs;
}	t_pipex;

void	error()
{
	printf("error");
	exit(0);
}

void	ft_close_all_fds(t_pipex *pipex)
{
	int	j;

	j = 0;
	close(pipex->fd1);
	close(pipex->fd2);
	while (j < pipex->pipe_num && pipex->pipes)
	{
		close(pipex->pipes[j][0]);
		close(pipex->pipes[j][1]);
		j++;
	}
}

int	ft_find_path(int cmd_i, t_pipex *pipex)
{
	int		j;
	char	*path;
	char	*fpath;

	j = 0;
	while (pipex->paths[j])
	{
		path = ft_strjoin(pipex->paths[j], "/");
		fpath = ft_strjoin(path, pipex->newargvs[cmd_i][0]);
		free(path);
		if (access(fpath, 0) == 0)
		{
			free(pipex->newargvs[cmd_i][0]);
			pipex->newargvs[cmd_i][0] = fpath;
			return (1);
		}
		else
			free(fpath);
		j++;
	}
	return (0);
}

int	ft_set_stdin(int cmd_i, t_pipex *pipex)
{
	if (cmd_i == 0)
		return (pipex->fd1);
	else
		return (pipex->pipes[cmd_i - 1][0]);
}

int	ft_set_stdout(int cmd_i, t_pipex *pipex)
{
	if (cmd_i == pipex->cmd_num - 1)
		return (pipex->fd2);
	else
		return (pipex->pipes[cmd_i][1]);
}

void	ft_child(int cmd_i, t_pipex *pipex)
{
	dup2(ft_set_stdin(cmd_i, pipex), STDIN_FILENO);
	dup2(ft_set_stdout(cmd_i, pipex), STDOUT_FILENO);
	ft_close_all_fds(pipex);
	ft_find_path(cmd_i, pipex);
	if (execve(pipex->newargvs[cmd_i][0], pipex->newargvs[cmd_i], NULL) == -1)
		error();
}

void	ft_init_pipex(t_pipex *pipex)
{
	pipex->cmd_num = 0;   // cmd, ls -l 같은 애들 갯수
	pipex->pipe_num = 0;   // 쓸 파이프의 갯수
	pipex->fd1 = -1;
	pipex->fd2 = -1;
	pipex->paths = NULL;   // PATH= 의 경로
	pipex->pipes = NULL;
	pipex->newargvs = NULL;		// 명령어를 저장
}

void	ft_make_paths(char **envp, t_pipex *pipex)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	if (ft_strncmp("PATH", *envp, 4))
		error();
	pipex->paths = ft_split(*envp + 5, ':');
}

void	ft_make_newarvs(char **argv, t_pipex *pipex)
{
	int	i;
	
	pipex->newargvs = malloc(sizeof(char **) * pipex->cmd_num);
	i = 0;
	while (i < pipex->cmd_num)
	{
		pipex->newargvs[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
}

void	ft_make_pipes(t_pipex *pipex)
{
	int	i;
	int	pipe_res;

	pipex->pipes = malloc(sizeof(int *) * pipex->pipe_num);
	i = 0;
	while (i < pipex->pipe_num)
	{
		pipex->pipes[i] = malloc(sizeof(int) * 2);
		pipe_res = pipe(pipex->pipes[i]);
		if (pipe_res == -1)
			error();
		i++;
	}
}

void	ft_make_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (argc < 5)
	{
		printf("not 5");
		exit(0);
	}
	ft_init_pipex(pipex);
	pipex->cmd_num = argc - 3;
	pipex->pipe_num = pipex->cmd_num - 1;
	pipex->fd1 = open(argv[1], O_RDONLY);
	if (pipex->fd1 < 0)
		error();
	pipex->fd2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->fd1 < 0)
		error();
	ft_make_paths(envp, pipex);
	ft_make_newarvs(argv, pipex);
	ft_make_pipes(pipex);
}

int main(int argc, char **argv, char **envp)
{
	int		pid;
	t_pipex pipex;
	int		cmd_i;

	ft_make_pipex(argc, argv, envp, &pipex);
	cmd_i = 0;
	while (cmd_i < pipex.cmd_num)
	{
		ft_find_path(cmd_i, &pipex);
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			ft_child(cmd_i, &pipex);
		cmd_i++;
	}
	wait(NULL);
}