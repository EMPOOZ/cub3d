/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:48:25 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/30 14:17:28 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x > 1000 || y > 1000 || x <= 0 || y <= 0)
		return ;
	if (x + (y * mlx->line_length / 4) >= (mlx->line_length / 4) * 1000)
		return ;
	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	if (color != 0x980088)
		*(unsigned int *)dst = color;
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

int	color_get(t_img img, int x, int y)
{
	int	color;

	if (x + (y * img.line_length) >= img.line_length * img.height)
		return (0);
	color = *((unsigned int *)(img.addr + y * img.line_length
				+ x * (img.bits_per_pixel / 8)));
	return (color);
}
