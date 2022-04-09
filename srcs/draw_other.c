/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:16:14 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/09 12:21:39 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fac_x(t_zone *zone, int y)
{
	int	x;

	x = 0;
	while (x < 1000)
	{
		my_mlx_pixel_put(zone->mlx, x, y, zone->floor);
		my_mlx_pixel_put(zone->mlx, x, 999 - y, zone->ceiling);
		x++;
	}
}

void	draw_other(t_zone *zone)
{
	int					y;

	y = 0;
	while (y < 1000)
	{
		fac_x(zone, y);
		y++;
	}
}
