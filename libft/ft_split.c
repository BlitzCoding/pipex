/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonghlee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 11:52:14 by yonghlee          #+#    #+#             */
/*   Updated: 2022/03/23 16:51:01 by yonghlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*push_malloc(const char *s, int n)
{
	int		i;
	char	*res;

	i = 0;
	if (n == 0)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

static char	**malloc_free(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static int	str_in_char(char const *s, char c)
{
	int	flag;
	int	i;
	int	count;

	count = 0;
	flag = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (flag == 1 && s[i] != c)
		{
			count++;
			flag = 0;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		index;
	int		i;
	int		copy;

	index = -1;
	i = 0;
	result = (char **)malloc(sizeof(char *) * (str_in_char(s, c) + 1));
	if (!result)
		return (NULL);
	while (++index < str_in_char(s, c) && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		copy = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		result[index] = push_malloc(&s[copy], i - copy);
		if (result[index] == 0)
			return (malloc_free(result));
	}
	result[index] = NULL;
	return (result);
}
