/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalv <marcoalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:23:00 by marcoalv          #+#    #+#             */
/*   Updated: 2024/02/16 19:56:09 by marcoalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	n;
	size_t	i;
	size_t	aux;

	i = 0;
	if (!s[i])
		return (NULL);
	n = ft_strlen(s);
	ptr = (char *)malloc(n + 2 * sizeof(char));
	if (!ptr || n == 0)
		return (NULL);
	aux = n;
	if (n <= ft_strlen(s) || n > ft_strlen(s))
	{
		while (aux-- || s[i] != '\0')
		{
			ptr[i] = s[i];
			i ++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}

char	*ft_next(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	temp = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		temp[j++] = buffer[i++];
	free(buffer);
	return (temp);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	if (!line)
		return (NULL);
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *buffer_prime)
{
	char	*buffer_read;
	char	*temp;
	int		byte_read;

	if (!buffer_prime)
		buffer_prime = ft_calloc(1, 1);
	buffer_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(buffer_read, '\n'))
	{
		byte_read = read(fd, buffer_read, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer_read);
			return (NULL);
		}
		if (byte_read == 0)
			break ;
		buffer_read[byte_read] = 0;
		temp = ft_strjoin(buffer_prime, buffer_read);
		free(buffer_prime);
		buffer_prime = temp;
	}
	free(buffer_read);
	return (buffer_prime);
}

char	*get_next_line(int fd)
{
	static char		*buffer_gnl;
	char			*line;
	char			*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer_gnl = read_file(fd, buffer_gnl);
	if (!buffer_gnl)
		return (NULL);
	new_line = ft_strchr(buffer_gnl, '\n');
	if (new_line)
	{
		line = ft_line(buffer_gnl);
		buffer_gnl = ft_next(buffer_gnl);
		return (line);
	}
	line = ft_strdup(buffer_gnl);
	buffer_gnl = ft_next(buffer_gnl);
	return (line);
}
