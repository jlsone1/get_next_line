/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javsanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:01:00 by javsanch          #+#    #+#             */
/*   Updated: 2022/11/17 12:07:34 by javsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"


int main (void)
{
	int	fd;
	int	i;

	
	i = 0;
	fd = open("/Users/javsanch/Desktop/get_next_line/get_next_line.c", O_RDONLY);
	printf("%d\n", fd);
	printf("%d\n", BUFFER_SIZE);

char *line = NULL;
	
	while (i < 13)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}

	system("leaks a.out");

}



