/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:43:32 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/29 13:06:41 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_init(t_draw *draw, t_zone *zone)
{
	draw->pos_x = (float)zone->pos_x;
	draw->pos_y = (float)zone->pos_y;
	draw->dir_x = -1.0;
	draw->dir_y = 0.0;
	draw->plane_x = 0.0;
	draw->plane_y = 0.66;
	draw->time = 0;
	draw->old_time = 0;
}

void	create_window(t_mlx *mlx)
{
	ft_putstr_fd("INIT MLX\n", 1);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		ft_putstr_fd("ERROR.1\n", 1);
	mlx->mlx_win = mlx_new_window (mlx->mlx_ptr, 1000, 1000, "cub3d");
	if (!mlx->mlx_ptr)
		ft_putstr_fd("ERROR.2\n", 1);
	mlx->mlx_img = mlx_new_image (mlx->mlx_ptr, 1000, 1000);
	if (!mlx->mlx_ptr)
		ft_putstr_fd("ERROR.3\n", 1);
	mlx->addr = mlx_get_data_addr(mlx->mlx_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	if (!mlx->mlx_ptr)
		ft_putstr_fd("ERROR.4\n", 1);
}

int	rendering(t_zone *zone)
{
	t_draw	draw;

	draw_init(&draw, zone);
	dda(&draw, zone);
	return (0);
}
