/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_other.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:16:14 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/06 17:26:27 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fac_x(t_draw *draw, t_zone *zone, t_floor_and_celing *fac, int y)
{
	int	x;

	x = 0;
	while (x < 1000)
	{
		fac->cell_x = (int)fac->floor_x;
		fac->cell_y = (int)fac->floor_y;
		fac->tx = (int)(zone->texture[0].line_length * (fac->floor_x
					- fac->cell_x)) & (zone->texture[0].line_length - 1);
		fac->ty = (int)(zone->texture[0].height * (fac->floor_y
					- fac->cell_y)) & (zone->texture[0].height - 1);
		fac->floor_x += fac->floor_step_x;
		fac->floor_y += fac->floor_step_y;
		fac->floor_tex = 3;
		fac->ceiling_tex = 6;
		my_mlx_pixel_put(zone->mlx, x, y, zone->floor);
		my_mlx_pixel_put(zone->mlx, x, 999 - y, zone->ceiling);
		x++;
	}
}

void	fac_init(t_draw *draw, t_zone *zone, t_floor_and_celing *fac, int y)
{
	fac->ray_dir_x0 = draw->dir_x - draw->plane_x;
	fac->ray_dir_y0 = draw->dir_y - draw->plane_y;
	fac->ray_dir_x1 = draw->dir_x + draw->plane_x;
	fac->ray_dir_y1 = draw->dir_y + draw->plane_y;
	fac->p = y - 1000 / 2;
	fac->pos_z = 0.5 * 1000;
	fac->row_distance = fac->pos_z / fac->p;
	fac->floor_step_x = fac->row_distance * fac->ray_dir_x0;
	fac->floor_step_y = fac->row_distance * fac->ray_dir_y0;
	fac->floor_x = fac->row_distance * fac->ray_dir_x1;
	fac->floor_y = fac->row_distance * fac->ray_dir_y1;
}

void	draw_other(t_draw *draw, t_zone *zone)
{
	t_floor_and_celing	fac;
	int					y;

	y = 0;
	while (y < 1000)
	{
		fac_init(draw, zone, &fac, y);
		fac_x(draw, zone, &fac, y);
		y++;
	}
}
