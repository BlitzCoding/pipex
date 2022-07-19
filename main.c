/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:31:06 by yonghlee          #+#    #+#             */
/*   Updated: 2022/07/19 16:13:49 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parse_envp(char **cmd, char **envp)
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
	cmd = ft_split(envp[i], ':');
}

void	parse_argv(int argc, char **argv, t_pipex *pipex)
{
	int	i;
	int idx;

	i = 1;  // cmd만 추출해야됨
	idx = 0;
	while (++i < argc - 1)
	{
		pipex->path_cmd[idx] = ft_split(argv[i], ' ');
		if (!(pipex->path_cmd[idx]))
			print_error(PARSE_FAIL);
		idx++;
	}
	int tmp = 0;
	while(pipex->path_cmd[tmp])
	{
		printf("now idx : %d\n", tmp);
		for (int i = 0; i < 2; i++)
		{
			printf("idx's path_cmd : %s\n", pipex->path_cmd[idx][i]);
		}
		printf("=====================\n");
		tmp++;
	}
}

void	init_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (argc < 5)
		print_error(INPUT_FAIL);
	pipex->infile = ft_strdup(argv[1]);
	pipex->outfile = ft_strdup(argv[argc - 1]);
	if (!(pipex->infile) || !(pipex->outfile))
		print_error(OPEN_FAIL);
	parse_envp(pipex->path, envp);
	parse_argv(argc, argv, pipex);
}

// O_RDWR : 읽고 쓰고 모두 가능하도록, O_CREAT : 존재하지 않으면 새로 만들라는 뜻
// O_TRUNC : 이미 존재하는 파일이며 파일의 내용 삭제하여 파일의 크기 0으로 만들어라

int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	init_pipex(argc, argv, envp, &pipex);

	// pipex.infile = open(argv[1], O_RDONLY);
	// if (pipex.infile == -1)
	// 	print_error(OPEN_FAIL);
	// // O_CREAT : read 4, write 2, execute 1 => 8진수
	// pipex.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	// if (pipex.outfile == -1)
	// 	print_error(OPEN_FAIL);
}