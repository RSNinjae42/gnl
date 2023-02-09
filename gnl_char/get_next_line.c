/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/02/09 17:48:33 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *s)
{
	char	*b;
	char	*aux;
	int		x;

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
		aux = ft_strjoin(s, b);
		free (b);
		free (s);
		if (!aux)
			return (NULL);
		s = aux;
		if (check_newline(s) == 1)
			break ;
	}
	return (s);
}

static int	s_line(char *s, char **line)
{
	int	x;

	*line = ft_newline(s, line);
	if (!*line)
		return (1);
	x = 0;
	while (s[x])
	{
		line[0][x] = s[x];
		if (s[x] == '\n')
			break ;
		x++;
	}
	line[0][x + 1] = '\0';
	return (0);
}

static int	ft_clean(char **s)
{
	char	*aux;
	int		x;
	int		y;

	x = 0;
	while (s[0][x] != '\n')
		x++;
	aux = malloc(sizeof(char) * (ft_strlen(s[0]) - x) + 1);
	if (!aux)
		free (aux);
	y = 0;
	x++;
	while (s[0][x])
	{
		aux[y] = s[0][x];
		y++;
		x++;
	}
	aux[y] = '\0';
	free (*s);
	s[0] = aux;
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
	line = NULL;
	x = s_line(s, &line);
	if (x == 1)
	{
		free (line);
		return (NULL);
	}
	x = ft_clean(&s);
	if (x == 1)
	{
		free (s);
		free (line);
		return (NULL);
	}
	return (line);
}
