/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalv <marcoalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:44:41 by marcoalv          #+#    #+#             */
/*   Updated: 2024/01/03 18:57:06 by marcoalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	char		*line;
	clock_t		inicio;
	clock_t		final;
	double		time;
	int			fd;

	inicio = clock();
	fd = open("examples/100K.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("File not opened");
		return (1);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("\nLINE--->: %s", line);
		free(line);
	}
	close(fd);
	final = clock();
	time = (double)(final - inicio) / CLOCKS_PER_SEC;
	printf("\nExecution time for 100Kb: %f(s)\n", time);
	return (0);
}
