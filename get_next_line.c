/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalv <marcoalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:23:00 by marcoalv          #+#    #+#             */
/*   Updated: 2024/01/03 18:44:18 by marcoalv         ###   ########.fr       */
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

	n = ft_strlen(s);
	ptr = (char *)malloc(n + 1 * sizeof(char));
	if (n == 0)
		return (ptr);
	i = 0;
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

char	**ft_free(char **result, int co)
{
	int	f;

	if (!result || !*result || !**result)
		return (NULL);
	f = 0;
	while (f < co)
	{
		free(result[f]);
		f++;
	}
	free(result);
	return (NULL);
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
		temp[j++] = buffer[i++];
	ft_free(&buffer, ft_strlen(buffer));
	return (temp);
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
			return (*ft_free(&buffer_read, ft_strlen(buffer_read)));
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
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer_gnl = read_file(fd, buffer_gnl);
	if (!buffer_gnl || !*buffer_gnl)
		return (NULL);
	line = ft_strchr(buffer_gnl, '\n');
	if (line)
	{
		*line = '\0';
		temp = ft_strdup(buffer_gnl);
		free(buffer_gnl);
		buffer_gnl = ft_strdup(line + 1);
		return (temp);
	}
	temp = ft_strdup(buffer_gnl);
	free(buffer_gnl);
	if (ft_strchr(temp, '\0'))
		return (temp);
	buffer_gnl = ft_next(buffer_gnl);
	ft_free(&buffer_gnl, ft_strlen(buffer_gnl));
	return (temp);
}
