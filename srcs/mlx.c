/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:48:25 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/26 15:03:00 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		dst = mlx->addr + (y * mlx->line_length + x
				* (mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	verline(int x, t_draw *draw, t_zone *zone)
{
	int	y;

	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		my_mlx_pixel_put(zone->mlx, x, y, draw->color);
		y++;
	}
}
