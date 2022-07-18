/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:35:01 by yonghlee          #+#    #+#             */
/*   Updated: 2022/07/18 13:01:07 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write (fd, &(*s), 1);
		s++;
	}
}

void	print_error(int status)
{
	if (status == INPUT_FAIL)
	{
		ft_putstr_fd("Error : You must input 4 status", 1);
		exit(0);
	}
	else if (status == OPEN_FAIL)
	{
		ft_putstr_fd("Error : Open Fail", 1);
		exit(0);
	}
}