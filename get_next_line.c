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
	n = ft_strlen(s);
	ptr = (char *)malloc(n + 1 * sizeof(char));
	if (n == 0)
		return (ptr);
	if (!ptr || !s || !s[i])
		return (NULL);
	aux = n;
	if (n == 0)
		return (NULL);
	else if (n <= ft_strlen(s) || n > ft_strlen(s))
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
	temp = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!temp || !buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[j++] = buffer[i++];
		if (buffer[i + 1] == '\0')
			return (NULL);
	}
	free(buffer);
	return (temp);
}

char	*ft_line(char *buffer, char *new_line)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_calloc(ft_strlen(buffer) + 2, sizeof(char));
	if (!line || !buffer || !buffer[0] || ft_strlen(buffer) == 0)
		return (NULL);
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = buffer[i];
	line[i + 1] = '\0';
	free(buffer);
	buffer = ft_strdup(new_line + 1);
	return (line);
}

char	*read_file(int fd, char *buffer_prime)
{
	char	*buffer_read;
	int		byte_read;

	if (!buffer_prime)
		buffer_prime = ft_calloc(1, 1);
	buffer_read = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read >= 0 && !ft_strchr(buffer_prime, '\n'))
	{
		byte_read = read(fd, buffer_read, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer_read);
			return (NULL);
		}
		if (byte_read == 0)
			break ;
		buffer_read[byte_read] = '\0';
		buffer_prime = ft_strjoin(buffer_prime, buffer_read);
		if (ft_strchr(buffer_prime, '\n'))
			break ;
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
	if (!buffer_gnl || !*buffer_gnl)
		return (NULL);
	new_line = ft_strchr(buffer_gnl, '\n');
	if (new_line)
	{
		line = ft_line(buffer_gnl, new_line);
		return (line);
	}
	line = ft_strdup(buffer_gnl);
	free(buffer_gnl);
	buffer_gnl = ft_next(buffer_gnl); // buffer_gnl = NULL;
	return (line);
}
