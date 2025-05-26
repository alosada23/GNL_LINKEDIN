/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alosada- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:47:01 by alosada-          #+#    #+#             */
/*   Updated: 2025/04/07 10:47:04 by alosada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(storage, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(storage);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		storage = ft_strjoin(storage, buffer);
	}
	free(buffer);
	return (storage);
}

char	*ft_update_storage(char *storage)
{
	char	*newline;
	char	*new_storage;

	newline = ft_strchr(storage, '\n');
	if (!newline)
	{
		free(storage);
		return (NULL);
	}
	new_storage = malloc(ft_strlen(newline + 1) + 1);
	if (!new_storage)
		return (NULL);
	ft_copy_s1(new_storage, newline + 1);
	free(storage);
	return (new_storage);
}

char	*ft_separate_line(char *source)
{
	int		i;
	char	*print;

	i = 0;
	while (source[i] != '\n' && source[i] != '\0')
		i++;
	print = malloc(i + (source[i] == '\n') + 1);
	if (!print)
		return (NULL);
	i = 0;
	while (source[i] != '\n' && source[i] != '\0')
	{
		print[i] = source[i];
		i++;
	}
	if (source[i] == '\n')
	{
		print[i] = '\n';
		i++;
	}
	print[i] = '\0';
	return (print);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (storage)
		{
			free(storage);
			storage = NULL;
		}
		return (NULL);
	}
	if (!storage)
		storage = ft_calloc(1, 1);
	storage = read_line(fd, storage);
	if (!storage || !storage[0])
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	line = ft_separate_line(storage);
	storage = ft_update_storage(storage);
	return (line);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
