/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alosada- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:47:17 by alosada-          #+#    #+#             */
/*   Updated: 2025/04/07 10:47:19 by alosada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdint.h> 

char	*ft_copy_s1(char *joined, const char *s1)
{
	int	i;

	i = 0;
	while (s1 && s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	joined[i] = '\0';
	return (joined);
}

char	*ft_copy_s2(char *joined, const char *s2, int start)
{
	int	j;

	j = 0;
	while (s2 && s2[j])
	{
		joined[start + j] = s2[j];
		j++;
	}
	joined[start + j] = '\0';
	return (joined);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*joined;
	int		len1;

	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = ft_calloc(1, 1);
		if (!s1)
			return (NULL);
	}
	len1 = ft_strlen(s1);
	joined = malloc(len1 + ft_strlen(s2) + 1);
	if (!joined)
	{
		free(s1);
		return (NULL);
	}
	ft_copy_s1(joined, s1);
	ft_copy_s2(joined, s2, len1);
	free(s1);
	return (joined);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total;
	unsigned char	*ptr;
	size_t			i;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	total = count * size;
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
