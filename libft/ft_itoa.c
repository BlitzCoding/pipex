/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:37:57 by yonghlee          #+#    #+#             */
/*   Updated: 2022/03/23 16:49:14 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_num(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*result;
	long	nb;

	nb = n;
	size = count_num(nb);
	result = (char *)malloc(sizeof(char) * size + 1);
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		result[--size] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (result);
}
