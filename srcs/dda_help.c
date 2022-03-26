/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:37 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/26 14:46:01 by rmicheli         ###   ########.fr       */
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

void	draw_buffer(int buffer[2880][5120], t_zone *zone)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < 2880)
	{
		while (x < 5120)
			my_mlx_pixel_put(zone->mlx, x, y, buffer[y][x]);
	}
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
	text_draw->tex_x = (int)(text_draw->wall_x * (double)zone->width);
	if (draw->side == 0 && draw->ray_dir_x > 0)
		text_draw->tex_x = zone->texture[0].line_length - text_draw->tex_x - 1;
	if (draw->side == 1 && draw->ray_dir_y < 0)
		text_draw->tex_x = zone->texture[0].line_length
			- text_draw->tex_x - 1;
	text_draw->step = 1.0 * zone->texture[0].line_length / zone->height;
	text_draw->tex_pos = (draw->draw_start - 100 - zone->height
			/ 2 + zone->height / 2) * text_draw->step;
}

void	draw_texture(t_draw *draw, t_zone *zone, int x, int buffer[2880][5120])
{
	t_texture_draw	text_draw;
	uint32_t		color;
	int				y;

	y = 0;
	texture_init(draw, zone, &text_draw);
	while (y < draw->draw_end)
	{
		text_draw.tex_y = (int)text_draw.tex_pos & (zone->texture[0].height
				- 1);
		text_draw.tex_pos += text_draw.step;
		color = zone->texture[text_draw.tex_num].addr[zone->texture[0].height
			* text_draw.tex_x * text_draw.tex_y];
		if (draw->side == 1)
			color = (color >> 1) & 8355711;
		buffer[y][x] = color;
	}
}
