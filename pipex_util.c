/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <yonghlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:35:01 by yonghlee          #+#    #+#             */
/*   Updated: 2022/07/20 11:50:17 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	else if (status == PARSE_FAIL)
	{
		ft_putstr_fd("Error : Parse Fail", 1);
		exit(0);
	}
	else if (status == PIPE_FAIL)
	{
		ft_putstr_fd("Error : Pipe Fail", 1);
		exit(0);
	}
}