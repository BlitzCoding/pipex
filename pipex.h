/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:31:00 by yonghlee          #+#    #+#             */
/*   Updated: 2022/07/19 16:13:55 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define INPUT_FAIL		0
# define OPEN_FAIL		1
# define PARSE_FAIL		2

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
	char	*infile;
	char 	*outfile;
	char	**path;
	char	***path_cmd;
	bool	is_here;	// here_dox 임시;
}	 t_pipex;



void	print_error(int status);
void	ft_putstr_fd(char *s, int fd);

#endif