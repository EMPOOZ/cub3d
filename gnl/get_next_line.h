/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 09:44:06 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/21 18:53:25 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

char	*search_line(const char *s);
size_t	ft_strlen(const char *p);
char	*get_next_line(int fd);
char	*ft_strjoin1(char *s1, char *s2);

#endif