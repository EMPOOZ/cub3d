/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:22:16 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/24 15:17:40 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda_init2(t_draw *draw, t_zone *zone)
{
	draw->line_height = (int)(zone->image_y / draw->perp_wall_dist);
	draw->draw_start = -draw->line_height / 2 + zone->image_y / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = draw->line_height / 2 + zone->image_y / 2;
	if (draw->draw_end >= zone->image_y)
		draw->draw_end = zone->image_y - 1;
}

void	while_hit(t_draw *draw, t_zone *zone)
{
	while (draw->hit == 0)
	{
		if (draw->side_dist_x < draw->side_dist_y)
		{
			draw->side_dist_x += draw->delta_dist_x;
			draw->map_x += draw->step_x;
			draw->side = 0;
		}
		else
		{
			draw->side_dist_y += draw->delta_dist_y;
			draw->map_y += draw->step_y;
			draw->side = 1;
		}
		if (zone->matrice > 0)
			draw->hit == 1;
	}
}

void	step(t_draw *draw, t_zone *zone)
{
	if (draw->ray_dir_x < 0)
	{
		draw->step_x = -1;
		draw->side_dist_x = (zone->image_x - draw->map_x) * draw->delta_dist_x;
	}
	else
	{
		draw->step_x = 1;
		draw->side_dist_x = (draw->side_dist_x + 1.0 - zone->image_x)
			* draw->delta_dist_x;
	}
	if (draw->ray_dir_y < 0)
	{
		draw->step_y = -1;
		draw->side_dist_y = (zone->image_y - draw->map_y) * draw->delta_dist_y;
	}
	else
	{
		draw->step_y = 1;
		draw->side_dist_y = (draw->side_dist_y + 1.0 - zone->image_y)
			* draw->delta_dist_y;
	}
}

void	dda_init(t_draw *draw, t_zone *zone, int x)
{
	draw->camera_x = 2 * x / zone->weight - 1;
	draw->ray_dir_x = draw->dir_x + draw->plane_x * draw->camera_x;
	draw->ray_dir_y = draw->dir_y + draw->plane_y * draw->camera_x;
	draw->map_x = zone->image_x;
	draw->map_y = zone->image_y;
	if (draw->ray_dir_x == 0)
		draw->delta_dist_x = abs(1 / draw->ray_dir_x);
	else
		draw->delta_dist_x = 1e30;
	if (draw->ray_dir_y == 0)
		draw->delta_dist_y = abs(1 / draw->ray_dir_y);
	else
		draw->delta_dist_y = 1e30;
	draw->hit = 0;
}

void	dda(t_draw *draw, t_zone *zone)
{
	int	x;

	x = -1;
	while (++x < zone->weight)
	{
		dda_init(draw, zone, x);
		step(draw, zone);
		while_hit(draw, zone);
		if (draw->side == 0)
			draw->perp_wall_dist = (draw->side_dist_x - draw->delta_dist_x);
		else
			draw->perp_wall_dist = (draw->side_dist_y - draw->delta_dist_y);
		dda_init2(draw, zone);
		draw->color = 16711680;
		verline (x, draw, zone);
	}
}
