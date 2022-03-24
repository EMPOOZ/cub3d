/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:43:32 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/22 13:01:54 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	drawing(t_draw *draw, t_zone *zone)
{
	while (1)
	{
		dda(draw, zone);
	}
}

void	draw(t_zone *zone)
{
	t_draw	*draw;

	draw_init(draw, zone);
	drawing(draw, zone);
}

void	create_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window (mlx->mlx_ptr,
			5120, 2880, "cub3d");
	mlx->mlx_img = mlx_new_image (mlx->mlx_ptr, 5120, 2880);
	mlx->addr = (mlx->mlx_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

int	rendering(t_zone *zone)
{
	create_window(zone->mlx);
	draw(zone);
	mlx_put_image_to_window(zone->mlx->mlx_ptr,
		zone->mlx->mlx_win, zone->mlx->mlx_img, 5120, 2880);
}
