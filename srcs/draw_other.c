/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:16:14 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/07 14:48:16 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fac_x(t_draw *draw, t_zone *zone, t_floor_and_celing *fac, int y)
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

void	draw_other(t_draw *draw, t_zone *zone)
{
	t_floor_and_celing	fac;
	int					y;

	y = 0;
	while (y < 1000)
	{
		fac_x(draw, zone, &fac, y);
		y++;
	}
}
