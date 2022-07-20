/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:31:00 by yonghlee          #+#    #+#             */
/*   Updated: 2022/07/20 15:28:39 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define INPUT_FAIL		0
# define OPEN_FAIL		1
# define PARSE_FAIL		2
# define PIPE_FAIL		3
# define FORK_FAIL		4
# define MALLOC_FAIL	5

#include "libft/libft.h"

# include <stdio.h>  //tmp;
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <stdbool.h>

typedef struct s_pipex
{
	int		cmd_num;
	int		pipe_num;
	int		fd1;
	int		fd2;
	int		**pipe;
	char	**path;
	char	*exec_path;
	char	***argv_cmd;
	bool	is_here;	// here_dox 임시;
}	 t_pipex;

void	print_error(int status);

#endif