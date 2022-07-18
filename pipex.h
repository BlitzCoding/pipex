/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:31:00 by yonghlee          #+#    #+#             */
/*   Updated: 2022/07/18 13:42:30 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define INPUT_FAIL		0
# define OPEN_FAIL		1

typedef struct s_pipex
{
	int		infile;
	int 	outfile;
	char	**path;
}	 t_pipex;

# include <stdio.h>  //tmp;
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

void	print_error(int status);
void	ft_putstr_fd(char *s, int fd);

#endif