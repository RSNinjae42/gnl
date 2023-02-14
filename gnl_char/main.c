/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:13:47 by rodro             #+#    #+#             */
/*   Updated: 2023/02/14 16:58:53 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* XA PODER USAR OPEN */
#include <fcntl.h>

void	ft_leaks()
{
	system("leaks a.out");
}

/* int	main(void)
{
	int		fd;
	int		x;
	char	*line;

	//atexit(ft_leaks);
	fd = open("text", O_RDONLY);
	x = 0;
	while (x < 5)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		printf("%s", line);
		free (line);
		x++;
	}
	close (fd);
	return (0);
} */

int				main()
{
	int			fd;
	char		*str;
	int			i;

	i =0;
	atexit(ft_leaks);
	fd = open("text", O_RDONLY);
// 	get_next_line(fd, &str);
//	printf("%s", str);
str = get_next_line(fd);
	while ((i <= 6))
	{
        printf("line %i=>%s", i + 1, str);
		if (str && ft_strlen(str) > 0)
			free(str);
		i++;
		str = get_next_line(fd);
		// if (i == 5)
			// sleep(30);
	}
	//system("leaks a.out");
	return (0);
}
