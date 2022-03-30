/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:37 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/30 13:22:57 by tconwy           ###   ########.fr       */
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
	text_draw->tex_num = zone->matr_int[draw->map_x][draw->map_y] - 1;
	if (draw->side == 0)
		text_draw->wall_x = zone->pos_y + draw->perp_wall_dist
			* draw->ray_dir_y;
	else
		text_draw->wall_x = zone->pos_x + draw->perp_wall_dist
			* draw->ray_dir_x;
	text_draw->wall_x -= floor((text_draw->wall_x));
	text_draw->tex_x = (int)(text_draw->wall_x
			* (double)zone->texture[0].line_length);
	if (draw->side == 0 && draw->ray_dir_x > 0)
		text_draw->tex_x = zone->texture[0].line_length - text_draw->tex_x - 1;
	if (draw->side == 1 && draw->ray_dir_y < 0)
		text_draw->tex_x = zone->texture[0].line_length - text_draw->tex_x - 1;
	text_draw->step = 1.0 * zone->texture[0].height / draw->line_height;
	text_draw->tex_pos = (draw->draw_start - 1000
			/ 2 + draw->line_height / 2) * text_draw->step;
}

void	draw_texture(t_draw *draw, t_zone *zone, int x)
{
	t_texture_draw	text_draw;
	int				color;
	int				y;

	texture_init(draw, zone, &text_draw);
	y = draw->draw_start;
	while (y < draw->draw_end)
	{
		text_draw.tex_y = (int)text_draw.tex_pos
			& (zone->texture[text_draw.tex_num].height - 1);
		text_draw.tex_pos += text_draw.step;
		// color = zone->texture[text_draw.tex_num].addr[zone->texture[0].height
		// 	* text_draw.tex_x * text_draw.tex_y];
		color = color_get(zone->texture[text_draw.tex_num], text_draw.tex_x, text_draw.tex_y);
		if (draw->side == 1)
			color = (color >> 1) & 8355711;
		my_mlx_pixel_put(zone->mlx, x, y, color);
		y++;
	}
}
