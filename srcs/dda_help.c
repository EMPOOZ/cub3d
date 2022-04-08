/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:37 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/08 18:59:22 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_background(t_zone *zone)
{
	int	*image;

	ft_bzero(zone->mlx->addr, 1000 * 1000 * (zone->mlx->bits_per_pixel / 8));
	image = (int *)(zone->mlx->addr);
}

void	texture_init(t_draw *draw, t_zone *zone, t_texture_draw *text_draw)
{
	if (draw->side == 0)
		text_draw->wall_x = zone->draw->pos_y + draw->perp_wall_dist
			* draw->ray_dir_y;
	else
		text_draw->wall_x = zone->draw->pos_x + draw->perp_wall_dist
			* draw->ray_dir_x;
	text_draw->wall_x -= floor((text_draw->wall_x));
	text_draw->tex_x = (int)(text_draw->wall_x
			* (double)32.0);
	if (draw->side == 0 && draw->ray_dir_x > 0)
		text_draw->tex_x = 32.0
			- text_draw->tex_x - 1;
	if (draw->side == 1 && draw->ray_dir_y < 0)
		text_draw->tex_x = 32.0
			- text_draw->tex_x - 1;
	text_draw->step = 1.0 * 32.0
		/ draw->line_height;
	text_draw->tex_pos = (draw->draw_start - 1000
			/ 2 + draw->line_height / 2) * text_draw->step;
}

void	draw_texture(t_draw *draw, t_zone *zone, int x)
{
	t_texture_draw	text_draw;
	double			y_step;
	int				color;
	int				y;

	texture_init(draw, zone, &text_draw);
	if (draw->side == 1)
	{
		if (draw->ray_dir_y < 0)
			text_draw.tex_num = 2;
		else
			text_draw.tex_num = 3;
	}
	else if (draw->side == 0)
	{
		if (draw->ray_dir_x < 0)
			text_draw.tex_num = 0;
		else
			text_draw.tex_num = 1;
	}
	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		text_draw.tex_y = (int)text_draw.tex_pos & (32 - 1);
		text_draw.tex_pos += text_draw.step;
		color = color_get(zone->texture[text_draw.tex_num], text_draw.tex_x,
				text_draw.tex_y);
		color = color_shift_int(color, 0x000000, ((1000
						- draw->perp_wall_dist) / 1000) / 2);
		if (x >= 0 && x < 1000)
			my_mlx_pixel_put(zone->mlx, x, y + draw->perp_wall_dist, color);
		y++;
	}
}
