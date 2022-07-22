/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:35:01 by yonghlee          #+#    #+#             */
/*   Updated: 2022/07/22 12:30:21 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_pipex *pipex)
{
	return ;
}

void	print_error(int status, t_pipex *pipex)
{
	if (status == INPUT_FAIL)
		ft_putstr_fd("Error : You must input 4 status", 1);
	else if (status == OPEN_FAIL)
		ft_putstr_fd("Error : Open Fail", 1);
	else if (status == PARSE_FAIL)
		ft_putstr_fd("Error : Parse Fail", 1);
	else if (status == PIPE_FAIL)
		ft_putstr_fd("Error : Pipe Fail", 1);
	else if (status == FORK_FAIL)
		ft_putstr_fd("Error : Fork Fail", 1);
	else if (status == MALLOC_FAIL)
		ft_putstr_fd("Error : Malloc Fail", 1);
	else if (status == EXEC_FAIL)
		ft_putstr_fd("Error : Exec Fail", 1);
	else
		ft_putstr_fd("Error : I don't know But Fail", 1);
	free_all(pipex);
	exit(0);
}