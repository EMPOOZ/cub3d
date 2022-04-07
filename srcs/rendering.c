/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:43:32 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/07 15:07:01 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_init(t_draw *draw, t_zone *zone)
{
	draw->pos_x = (double)zone->pos_y;
	draw->pos_y = (double)zone->pos_x;
	draw->dir_x = -1.0;
	draw->dir_y = 0.0;
	draw->plane_x = 0.0;
	draw->plane_y = 0.66;
	draw->time = 0;
	draw->old_time = 0;
	draw->rot = 0;
	draw->zone = zone;
}

void	create_window(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window (mlx->mlx_ptr, 1000, 1000, "cub3d");
	mlx->mlx_img = mlx_new_image (mlx->mlx_ptr, 1000, 1000);
	mlx->addr = mlx_get_data_addr(mlx->mlx_img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

int	rendering(t_zone *zone)
{
	dda(zone->draw, zone);
	return (0);
}
