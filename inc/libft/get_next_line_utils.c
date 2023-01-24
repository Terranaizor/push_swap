/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:11:48 by nradin            #+#    #+#             */
/*   Updated: 2023/01/24 11:04:07 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s1 + j))
	{
		*(s3 + i) = *(s1 + j);
		i++;
		j++;
	}
	j = 0;
	while (*(s2 + j))
	{
		*(s3 + i) = *(s2 + j);
		i++;
		j++;
	}
	*(s3 + i) = 0;
	return (s3);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	i = size;
	while (i <= size)
	{
		if (*((char *)s + i) == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (len == 0)
		return (NULL);
	if (len < ft_strlen(s + start))
		sub = (char *)malloc(len + 1);
	else
		sub = (char *)malloc(ft_strlen(s + start) + 1);
	if (sub == NULL)
		return (NULL);
	i = 0;
	if (start < ft_strlen(s))
	{
		while (*(s + start + i) && i < len)
		{
			*(sub + i) = *(s + start + i);
			i++;
		}
	}
	*(sub + i) = 0;
	return (sub);
}
