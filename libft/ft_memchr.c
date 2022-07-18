/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:32:54 by yonghlee          #+#    #+#             */
/*   Updated: 2022/03/23 14:01:51 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*temp;

	temp = (const char *) s;
	while (n != 0)
	{
		if (*temp == (char)c)
			return ((void *)temp);
		temp++;
		n--;
	}
	return (NULL);
}
