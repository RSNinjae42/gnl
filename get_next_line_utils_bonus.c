/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:58 by rofuente          #+#    #+#             */
/*   Updated: 2023/02/20 17:39:10 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *s)
{
	free (s);
	s = NULL;
	return (s);
}

int	check_newline(char *s, int y)
{
	int	x;

	x = 0;
	if (y == 1)
	{
		while (s[x])
			x++;
		return (x);
	}
	else if (y == 0)
	{
		if (!s)
			return (0);
		while (s[x])
		{
			if (s[x] == '\n')
				return (1);
			x++;
		}
	}
	return (0);
}

char	*ft_strjoin(char *s, char *b)
{
	char	*r;
	int		x;
	int		y;

	if (!s)
		r = malloc(sizeof(char) * (check_newline(b, 1) + 1));
	else
		r = malloc(sizeof(char) * (check_newline(s, 1)
					+ check_newline(b, 1) + 1));
	if (!r)
		return (ft_free(r));
	x = 0;
	y = 0;
	if (s)
		while (s[y])
			r[x++] = s[y++];
	y = 0;
	while (b[y])
		r[x++] = b[y++];
	r[x] = '\0';
	ft_free(s);
	return (r);
}

char	*ft_newline(char *s, char **line)
{
	int	x;

	x = 0;
	while (s[x] != '\n' && s[x])
		x++;
	if (x == 1)
		line[0] = malloc(sizeof(char) * (x + 1));
	else
		line[0] = malloc(sizeof(char) * (x + 2));
	if (!line[0])
	{
		free (line[0]);
		return (NULL);
	}
	return (line[0]);
}

char	*ft_copy(char *s, char *aux)
{
	int	x;

	s = malloc(sizeof(char) * (check_newline(aux, 1) + 1));
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
