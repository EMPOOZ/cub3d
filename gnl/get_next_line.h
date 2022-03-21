/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 09:44:06 by tconwy            #+#    #+#             */
/*   Updated: 2021/10/18 14:10:21 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif
# include <stdlib.h>
# include <unistd.h>

char	*search_line(const char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *p);
char	*get_next_line(int fd);

#endif