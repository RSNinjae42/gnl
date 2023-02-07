/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:13:47 by rodro             #+#    #+#             */
/*   Updated: 2023/02/06 15:52:43 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* XA PODER USAR OPEN */
#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		x;
	char	*line;

	fd = open("text", O_RDONLY);
	x = 0;
	while (x < 2)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("NO PURULA\n");
			break ;
		}
		printf("%s", line);
		free (line);
		x++;
	}
	close (fd);
	return (0);
}
