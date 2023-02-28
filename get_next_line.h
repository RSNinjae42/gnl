/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodro <rodro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:14:41 by rofuente          #+#    #+#             */
/*   Updated: 2023/02/28 19:53:41 by rofuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* ---------- GNL ---------- */
char	*ft_read(int fd, char *s);
int		s_line(char *s, char **line);
int		ft_clean2(char **s, char *aux, int x);
int		ft_clean(char **s);
char	*get_next_line(int fd);

/* ---------- UTILS ---------- */
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_newline(char *s, char **line);
char	*ft_copy(char *s, char *aux);
char	*ft_free(char *s, char *b);
int		check_newline(char *s, int y);
#endif
