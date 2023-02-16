/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:58 by rofuente          #+#    #+#             */
/*   Updated: 2023/02/16 15:00:31 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* void	ft_free(char *s1, char *s2, char *s3, int x)
{
	if (s1)
		free (s1);
	if (s2)
		free (s2);
	if (s3)
		free (s3);
	if (x == 1)
	{
		if (s1)
			s1 = NULL;
		if (s2)
			s2 = NULL;
		if (s3)
			s3 = NULL;
	}
}
 */
/* int	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	return (x);
} */

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
		return (NULL);
	x = 0;
	y = 0;
	if (s)
		while (s[y])
			r[x++] = s[y++];
	y = 0;
	while (b[y])
		r[x++] = b[y++];
	r[x] = '\0';
	free (s);
	free (b);
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
