/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:34:14 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/19 15:39:13 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	c;

	c = 0;
	ft_putstr_fd("\ntrue1\n", 1);
	while (c < size && s1[c] && s2[c])
	{
		ft_putstr_fd("\ntrue2\n", 1);
		if (s1[c] != s2[c])
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
		ft_putstr_fd("\ntrue3\n", 1);
		c++;
	}
	ft_putstr_fd("\ntrue4\n", 1);
	if (c < size)
		return ((unsigned char)s1[c] - (unsigned char)s2[c]);
	ft_putstr_fd("\ntrue5\n", 1);
	return (0);
}
