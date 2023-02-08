/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:58 by rofuente          #+#    #+#             */
/*   Updated: 2023/02/08 20:18:19 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x])
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
	if (!r)
		return (NULL);
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
	return (r);
}

char	*ft_newline(char *s, char **line)
{
	int	x;

	x = 0;
	while (s[x] != '\n')
		x++;
	*line = malloc(sizeof(char) * (x + 1));
	if (!line)
		return (NULL);
	return (*line);
}

int	check_newline(char *s)
{
	int	x;

	if (!s)
		return (0);
	x = 0;
	while (s[x] && x < ft_strlen(s))
	{
		if (s[x] == '\n')
			return (1);
		x++;
	}
	return (0);
}
