/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/02/08 18:33:53 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *s)
{
	char	*b;
	int		x;
	int		y;

	x = 1;
	while (x != 0)
	{
		b = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!b)
			return (NULL);
		x = (int)read(fd, b, BUFFER_SIZE);
		if (x == 0 || x == -1)
		{
			free (b);
			return (NULL);
		}
		b[x] = '\0';
		s = ft_strjoin(s, b);
		free (b);
		y = check_newline(s);
		if (y == 1)
			break ;
	}
	return (s);
}

static int	s_line(char *s, char *line)
{
	int	x;

	line = ft_newline(s, line);
	if (!line)
		return (1);
	x = 0;
	while (s[x])
	{
		line[x] = s[x];
		if (s[x] == '\n')
			break ;
		x++;
	}
	line[x + 1] = '\0';
	return (0);
}

static int	ft_clean(char *s)
{
	char	*aux;
	int		x;
	int		y;

	x = 0;
	while (s[x] != '\n')
		x++;
	aux = malloc(sizeof(char) * (ft_strlen(s) - x) + 1);
	if (!aux)
		return (1);
	y = 0;
	while (s[x])
	{
		aux[y] = s[x];
		y++;
		x++;
	}
	free (s);
	s = aux;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0))
		return (NULL);
	s = ft_read(fd, s);
	if (!s)
		return (NULL);
	x = s_line(s, line);
	if (x == 1)
		return (NULL);
	x = ft_clean(s);
	if (x == 1)
	{
		free (s);
		return (NULL);
	}
	return (line);
}
