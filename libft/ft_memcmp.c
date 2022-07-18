/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:49:49 by yonghlee          #+#    #+#             */
/*   Updated: 2022/03/14 13:52:24 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*copy1;
	unsigned char	*copy2;
	size_t			i;

	copy1 = (unsigned char *)s1;
	copy2 = (unsigned char *)s2;
	i = 0;
	while (n != 0)
	{
		if (copy1[i] != copy2[i])
			return (copy1[i] - copy2[i]);
		i++;
		n--;
	}
	return (0);
}
