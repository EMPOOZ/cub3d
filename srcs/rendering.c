/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:43:32 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/26 16:50:38 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	drawing(t_draw *draw, t_zone *zone)
{
	while (1)
	{
		ft_putstr_fd("456\n", 1);
		dda(draw, zone);
		ft_putstr_fd("456\n", 1);
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
			1000, 1000, "cub3d");
	mlx->mlx_img = mlx_new_image (mlx->mlx_ptr, 1000, 1000);
	mlx->addr = mlx_get_data_addr(mlx->mlx_ptr, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	my_mlx_pixel_put(mlx, 500, 500, 1244523);
	mlx_put_image_to_window(mlx->mlx_ptr,
		mlx->mlx_win, mlx->mlx_img, 1000, 1000);
}

int	rendering(t_zone *zone)
{
	draw(zone);
	return (0);
}
