/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:47:47 by rofuente          #+#    #+#             */
/*   Updated: 2023/02/20 17:33:42 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		x;
	int		y;
	int		fd;
	char	*str;

	x = 1;
	while (x <= ac)
	{
		fd = open(av[x], O_RDONLY);
		y = 0;
		while (y < 4)
		{
			str = get_next_line(fd);
			printf("line %i=>%s", y + 1, str);
			free (str);
			y++;
		}
		x++;
	}
	return (0);
}
