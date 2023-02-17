/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:13:47 by rodro             #+#    #+#             */
/*   Updated: 2023/02/17 13:32:38 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* XA PODER USAR OPEN */
#include <fcntl.h>

void	ft_leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("text", O_RDONLY);
	while ((i <= 6))
	{
		str = get_next_line(fd);
		printf("line %i=>%s", i + 1, str);
		free(str);
		i++;
	}
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	return (0);
}
