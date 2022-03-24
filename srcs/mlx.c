/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:48:25 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/23 14:11:42 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_zone *zone, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 5120 && y >= 0 && y < 2880)
	{
		dst = zone->mlx->addr + (y * zone->mlx->line_length + x
				* (zone->mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	verline(int x, t_draw *draw, t_zone *zone)
{
	int	y;

	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		my_mlx_pixel_put(zone, x, y, draw->color);
		y++;
	}
}
