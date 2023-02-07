/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:36:37 by rodro             #+#    #+#             */
/*   Updated: 2023/02/06 16:26:35 by rodro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	add_a(char *b, t_list **a, int x)
{
	t_list	*new;
	t_list	*last;
	int		y;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (x + 1));	/*POSIBLE LEAK*/
	if (!new->content)
	{
		free (new);
		return ;
	}
	y = 0;
	while (b[y] && y < x)
	{
		new->content[y] = b[y];
		y++;
	}
	new->content[y] = '\0';
	if (!*a)
	{
		*a = new;
		return ;
	}
	last = ft_lstlast(*a);
	last->next = new;
}

void	ft_read(int fd, t_list **a)
{
	char	*b;
	int		x;

	x = 1;
	while (!ft_newline(*a) && x != 0)
	{
		b = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!b)
			return ;
		x = (int)read(fd, b, BUFFER_SIZE);
		if ((!*a && x == 0) || x == -1 || x == 0)
		{
			free (b);
			return ;
		}
		//b[x] = '\0';
		add_a(b, a, x);
		free (b);
	}
}

void	a_line(t_list *a, char **line)
{
	int		x;
	int		y;

	if (!a)
		return ;
	x = new_line(a, line);
	if (x == 1)
	{
		free (line);
		return ;
	}
	x = 0;
	while (a)
	{
		y = 0;
		while (a->content[y] && y < ft_strlen(a->content))
		{
			if (a->content[y] == '\n')
			{
				(*line)[x++] = a->content[y];
				break ;
			}
			(*line)[x++] = a->content[y++];
		}
		if (a->content[y] != '\n' || a->content[y] != '\0')
			a = a->next;
	}
	(*line)[x] = '\0';
}

int	clean(t_list **a)
{
	t_list	*last;
	t_list	*c;
	int		x;
	int		y;

	if (!a)
		return (1);
	c = malloc(sizeof(t_list));
	if (!c)
		return (1);
	c->next = NULL;
	last = ft_lstlast(*a);
	x = 0;
	while (last->content[x] && last->content[x] != '\n')
		x++;
	c->content = malloc(sizeof(char) * (ft_strlen(last->content) - x) + 1);	/*POSIBLE LEAK*/
	if (!c->content)
	{
		ft_free(c);
		return (1);
	}
	y = 0;
	while (last->content[x])
		c->content[y++] = last->content[x++];
	c->content[y] = '\0';
	ft_free(*a);
	*a = c;
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*a = NULL;
	char			*line;
	int				x;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0))
		return (NULL);
	ft_read(fd, &a);
	if (!a)
		return (NULL);
	a_line(a, &line);
	if (!line)
	{
		free (line);
		return (NULL);
	}
	x = clean(&a);
	if (!line || (x == 1))
	{
		free (line);
		ft_free(a);
		return (NULL);
	}
	if (line[0] == '\0')
		return (NULL);
	return (line);
}
