#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*read_file(int fd, char *buffer_prime)
{
	char	*buffer;
	int		byte_read;
    int     x;

	if (!buffer_prime)
		buffer_prime = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
    x = 0;

	while (byte_read > 0 && !ft_strchr(buffer_prime, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
        if (byte_read == 0)
            break;
		buffer[byte_read] = '\0';
		buffer_prime = ft_strjoin(buffer_prime, buffer);
        x += 1;
        printf("\nbyte read: %i, bucle times: %i\n", byte_read, x);
        if (ft_strchr(buffer_prime, '\n'))
            break;
	}

	free(buffer);
	return (buffer_prime);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
    char        *temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);

	buffer = read_file(fd, buffer);

	if (!buffer)
		return (NULL);

	line = ft_strchr(buffer, '\n');
	if (line)
    {
		*line = '\0';
        temp = ft_strdup(buffer);
        free(buffer);
        buffer = ft_strdup(line + 1);
        return(temp);
    }

    temp = ft_strdup(buffer);
    free(buffer);
    buffer = NULL;

	return (temp);
}
