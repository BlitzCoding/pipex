/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:42:58 by yonghlee          #+#    #+#             */
/*   Updated: 2022/03/14 13:30:32 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*s;

	s = src;
	tmp = dst;
	if (dst <= src)
	{
		while (len--)
			*tmp++ = *s++;
	}
	else
	{
		tmp += len;
		s += len;
		while (len--)
			*--tmp = *--s;
	}
	return (dst);
}
