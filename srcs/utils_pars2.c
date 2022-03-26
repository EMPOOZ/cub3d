/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pars2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:21:25 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/26 13:38:47 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*free_array(void **ptr, void *(f)(void *))
{
	int	a;

	a = 0;
	if (ptr == NULL)
		return (NULL);
	if (ptr != NULL && ptr[a] != NULL)
		array_clear(ptr, f);
	ft_free(ptr);
	return (NULL);
}

int	array_s(void **str)
{
	int	i;

	i = 0;
	while (str && *str)
	{
		str++;
		i++;
		if (i == 2147483467)
			return (-1);
	}
	return (i);
}

int	init_color(t_rgb rgb)
{
	int	color_int;

	color_int = rgb.r << 16 | rgb.g << 8 | rgb.b;
	return (color_int);
}

void	search_zone(t_zone *zone)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (zone->matrice[y])
	{
		x = 0;
		while (zone->matrice[y][x])
		{
			x++;
			if (zone->width < x)
				zone->width = x;
		}
		y++;
	}
	zone->height = y;
}
