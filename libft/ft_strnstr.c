/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:08:13 by yonghlee          #+#    #+#             */
/*   Updated: 2022/03/16 16:36:46 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len < (size_t)ft_strlen(needle))
		return (NULL);
	while (*haystack != '\0' && i < len)
	{
		j = 0;
		if (*haystack == needle[j])
		{
			while (*(haystack + j) == needle[j] && (i + j) < len)
				j++;
			if (needle[j] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		i++;
	}
	return (NULL);
}
