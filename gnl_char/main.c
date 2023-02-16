/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:13:47 by rodro             #+#    #+#             */
/*   Updated: 2023/02/16 17:05:42 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* XA PODER USAR OPEN */
#include <fcntl.h>

void	ft_leaks()
{
	system("leaks a.out");
}

int	main()
{
	int			fd;
	char		*str;
	int			i;

	i =0;
	//atexit(ft_leaks);
	fd = open("text", O_RDONLY);
	while ((i <= 3))
	{
		str = get_next_line(fd);
		printf("line %i=>%s", i + 1, str);
		free(str);
		i++;
	}
	//system("leaks a.out");
	return (0);
}
