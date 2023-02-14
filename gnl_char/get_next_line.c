/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:17:16 by rofuente          #+#    #+#             */
/*   Updated: 2023/02/14 17:09:33 by rodro            ###   ########.fr       */
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
		if (!aux)
			return (NULL);
		free (s);
		free (b);
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
		return (1);
	y = 0;
	x++;
	while (s[0][x])
	{
		aux[y] = s[0][x];
		y++;
		x++;
	}
	aux[y] = '\0';
	free (s[0]);
	s[0] = NULL;
	s[0] = ft_copy(s[0], aux);
	if (!s)
	{
		free (s);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;
	int			x;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) == -1)
	{
		free (s);
		s = NULL;
		return (NULL);
	}
	s = ft_read(fd, s);
	if (!s)
	{
		free(s);
		return (NULL);
	}
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
		free (line);
		return (NULL);
	}
	return (line);
}
