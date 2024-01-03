/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalv <marcoalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:23:00 by marcoalv          #+#    #+#             */
/*   Updated: 2024/01/03 17:41:18 by marcoalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	n;

	n = ft_strlen(s);
	ptr = (char *)malloc(n + 1 * sizeof(char));
	if(n == 0)
		return (ptr);
	ft_strlcpy(ptr, s, n + 1);
	return (ptr);
}

char	**ft_free(char **result, int co)
{
	int	f;
	
	if(!result || !*result || !**result)
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
	char	*bufferREAD;
	int		byte_read;

	if (!buffer_prime)
		buffer_prime = ft_calloc(1, 1);
	bufferREAD = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read >= 0 && !ft_strchr(buffer_prime, '\n'))
	{
		byte_read = read(fd, bufferREAD, BUFFER_SIZE);
		if (byte_read == -1)
			return (*ft_free(&bufferREAD, ft_strlen(bufferREAD)));
		if (byte_read == 0)
			break ;
		bufferREAD[byte_read] = '\0';
		buffer_prime = ft_strjoin(buffer_prime, bufferREAD);
		if (ft_strchr(buffer_prime, '\n'))
			break ;
	}
	free(bufferREAD);
	return (buffer_prime);
}

char	*get_next_line(int fd)
{
	static char		*bufferGNL;
	char			*line;
	char			*temp;
	char			**p_char;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	bufferGNL = read_file(fd, bufferGNL);
	printf("\nGNL-read(bufferGNL): %s\n", bufferGNL);
	if (!bufferGNL || !*bufferGNL)
		return (NULL);
	line = ft_strchr(bufferGNL, '\n');
	if (line)
	{
		*line = '\0';
		temp = ft_strdup(bufferGNL);
		free(bufferGNL);
		bufferGNL = ft_strdup(line + 1);
		return (temp);
	}
	temp = ft_strdup(bufferGNL);
	p_char = &bufferGNL;
	printf("\nGNL-bufferGNL: %p::%s\n", p_char, bufferGNL);
	free(bufferGNL);
	if (ft_strchr(temp, '\0'))
		return (temp);
	bufferGNL = ft_next(bufferGNL);
	return (temp);
}
