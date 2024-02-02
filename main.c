/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalv <marcoalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:44:41 by marcoalv          #+#    #+#             */
/*   Updated: 2024/01/25 17:18:31 by marcoalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	char		*line;
	clock_t		start;
	clock_t		end;
	double		time;
	int			fd;

	line = "Pointer to hold the current memmory being allocated";
	start = clock();

	//File Descriptor number to access a resources in Unix
	fd = open("examples/hola.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("File not opened");
		return (1);
	}

	//Read and print the lines usging Get Next Line function
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line == NULL)
			break ;
		printf("\nLINE--->: %s", line);
		free(line);
	}
	close(fd);
	end = clock();
	time = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nExecution time for 100Kb: %f(s)\n", time);
	return (0);
}
