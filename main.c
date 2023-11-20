#include "get_next_line.h"
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char *line;
    clock_t inicio;
    clock_t final;
    double  time;
    inicio = clock();
    int fd = open("examples/hola.txt", O_RDONLY);
    if(fd == -1)
    {
        perror("File not opened");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("line: %s", line);
        free(line);
    }
    close(fd);
    final = clock();
    time = (double) (final - inicio)/CLOCKS_PER_SEC;

    printf("\nTiempo de ejecución bytes 100K: %f(s)\n", time);
    return(0);
}