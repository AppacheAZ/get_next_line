#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <fcntl.h>

char    *get_next_line(int fd)
{
    char *buffer = malloc(BUFFER_SIZE);
    size_t read_bytes;

    if (buffer == NULL)
        return (NULL);
    if (fd == -1)
        return (NULL);
    read_bytes = read(fd, buffer, BUFFER_SIZE);
    if(read_bytes == 0)
    {
        free(buffer);
        return(NULL);
    }
    buffer[read_bytes] = '\0';
    return(buffer);
}