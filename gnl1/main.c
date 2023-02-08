/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:13:47 by rodro             #+#    #+#             */
/*   Updated: 2023/02/08 18:34:42 by rofuente         ###   ########.fr       */
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
	while (x < 5)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		//system("leaks a.out");
		printf("%s", line);
		x++;
	}
	close (fd);
	return (0);
}
