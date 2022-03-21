/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 09:44:13 by tconwy            #+#    #+#             */
/*   Updated: 2021/10/18 14:22:32 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*search_line(const char *s)
{
	size_t	g;

	g = 0;
	if (!s)
		return (0);
	while (s[g] != '\n')
	{
		if (!s[g])
			return (0);
		++g;
	}
	return ((char *)&s[g]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		y;
	int		m;
	char	*t;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	t = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2);
	if (!t)
		return (0);
	m = 0;
	y = 0;
	while (s1[m])
		t[y++] = s1[m++];
	m = 0;
	while (s2[m])
		t[y++] = s2[m++];
	t[y] = '\0';
	free(s1);
	return (t);
}

size_t	ft_strlen(const char *p)
{
	int	b;

	b = 0;
	while (p[b])
		b++;
	return (b);
}
