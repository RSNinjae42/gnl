/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:58 by rofuente          #+#    #+#             */
/*   Updated: 2023/02/15 15:02:56 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str && str[x])
		x++;
	return (x);
}

char	*ft_strjoin(char const *s, char const *b)
{
	char	*r;
	int		x;
	int		y;

	if (!s)
		r = malloc(sizeof(char) * (ft_strlen((char *)b) + 1));
	else
		r = malloc(sizeof(char) * (ft_strlen((char *)s)
					+ ft_strlen((char *)b) + 1));
	x = 0;
	y = 0;
	if (s)
	{
		while (s[y])
			r[x++] = s[y++];
	}
	y = 0;
	while (b[y])
		r[x++] = b[y++];
	r[x] = '\0';
	free ((char *)b);
	free ((char *)s);
	return (r);
}

char	*ft_newline(char *s, char **line)
{
	int	x;

	x = 0;
	while (s[x] != '\n' && s[x])
		x++;
	*line = malloc(sizeof(char) * (x + 2));
	if (!*line)
	{
		free (*line);
		return (NULL);
	}
	return (*line);
}

int	check_newline(char *s)
{
	int	x;

	if (!s)
		return (0);
	x = 0;
	while (s[x])
	{
		if (s[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}

char	*ft_copy(char *s, char *aux)
{
	int	x;

	s = malloc(sizeof(char) * (ft_strlen(aux) + 1));
	if (!s)
	{
		free (s);
		return (NULL);
	}
	x = 0;
	while (aux[x])
	{
		s[x] = aux[x];
		x++;
	}
	s[x] = '\0';
	free (aux);
	return (s);
}
