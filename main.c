/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:31:06 by yonghlee          #+#    #+#             */
/*   Updated: 2022/07/20 11:57:47 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_path(char **envp, t_pipex *pipex)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			break;
	}
	if (!envp[i])
		print_error(PARSE_FAIL);
	envp[i] = &envp[i][5];
	pipex->path = ft_split(envp[i], ':');
}

void	parse_argv_cmd(char **argv, t_pipex *pipex)
{
	int	i;

	i = 0;
	pipex->argv_cmd = malloc(sizeof(char **) * pipex->cmd_num);
	if (!pipex->argv_cmd)
		return (NULL);
	while (i < pipex->cmd_num)
	{
		pipex->argv_cmd[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
}

void	init_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->is_here = false; // 나중에
	if (argc < 5)
		print_error(INPUT_FAIL);
	pipex->cmd_num = argc - 3;
	pipex->pipe_num = pipex->cmd_num - 1;
	pipex->fd1 = open(argv[1], O_RDONLY);
	if (pipex->fd1 < 0)
		print_error(OPEN_FAIL);
	pipex->fd2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->fd2 < 0)
		print_error(OPEN_FAIL);
	find_path(envp, pipex);
	parse_argv_cmd(argv, pipex);
	set_pipe(pipex);
}

void	set_pipe(t_pipex *pipex)
{
	int	i;
	int	pipe_res;

	pipex->pipe = malloc(sizeof(int *) * pipex->pipe_num);
	i = 0;
	while (i < pipex->pipe_num)
	{
		pipex->pipe[i] = malloc(sizeof(int) * 2);
		if (!pipex->pipe[i])
			return (NULL);
		pipe_res = pipe(pipex->pipe[i]);
		if (pipe_res == -1)
			print_error(PIPE_FAIL);
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	pid_t	pid;

	init_pipex(argc, argv, envp, &pipex);

}