/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rofuente <rofuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:14:41 by rofuente          #+#    #+#             */
/*   Updated: 2023/02/16 14:58:32 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
/* XA PODER USAR READ */
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}t_list;

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_newline(char *s, char **line);
int		check_newline(char *s, int y);
char	*ft_copy(char *s, char *aux);
void	ft_free(char *s1, char *s2, char *s3, int x);
/*QUITAR ES DEL MAIN POR NORMINETTE*/
void	ft_leaks();
#endif
