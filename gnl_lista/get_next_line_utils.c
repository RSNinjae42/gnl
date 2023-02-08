/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:44:56 by rodro             #+#    #+#             */
/*   Updated: 2023/02/06 16:27:16 by rodro            ###   ########.fr       */
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

int	ft_newline(t_list *a)
{
	int		x;
	t_list	*aux;

	if (!a)
		return (0);
	aux = ft_lstlast(a);
	x = 0;
	while (aux->content[x] && x < ft_strlen(aux->content))
	{
		if (aux->content[x] == '\n' || aux->content[x] == '\0')
			return (1);
		x++;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux != NULL)
	{
		if (aux->next == NULL)
			break ;
		aux = aux->next;
	}
	return (aux);
}

int	new_line(t_list *a, char **line)
{
	int		x;
	int		len;
	t_list	*aux;

	len = 0;
	aux = a;
	while (aux)
	{
		x = 0;
		while (aux->content[x] && x < ft_strlen(aux->content))
		{
				len++;
			if (aux->content[x] == '\n')
				break ;
			x++;
		}
		aux = aux->next;
	}
	*line = malloc(sizeof(char) * (len + 1));	/*FSANITIZE MARCA UN LEAK AQUI*/
	if (!*line)
	{
		free (*line);
		free (line);
		return (1);
	}
	return (0);
}

void	ft_free(t_list *a)
{
	t_list	*aux;
	t_list	*next;

	aux = a;
	while (aux)
	{
		free(aux->content);
		next = aux->next;
		free (aux);
		aux = next;
	}
}
