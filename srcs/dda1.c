/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:22:16 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/03 15:01:00 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_pos	new_pos(double x, double y, double z)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	return (pos);
}

t_pos	textures_index(t_pos pos, float offset, float height, int side)
{
	double	i_x;
	double	i_y;

	if (side)
		i_x = (fmod(fmod(pos.x, 32.0), 32.0));
	else
		i_x = (fmod(fmod(pos.y, 32.0), 32.0));
	i_y = (32.0 * offset / 2) / (height + (offset));
	return (new_pos(i_x, i_y, 0));
}

void	fill_with_texture(t_img *text, t_pos pos, t_zone *zone, t_pos index)
{
	double	height;
	double	y_step;
	int		bytes;
	int		color;

	height = zone->draw->line_height;
	y_step = ((float)text->height - (index.y * 2))
		/ (height + (1000 - height) / 32.0);
	bytes = (text->bits_per_pixel / 8);
	color = 0;
	while (pos.y < height + (1000 - height) / 2)
	{
		color = color_get(*text, (int)index.x, (int)index.y);
		color = color_shift_int(color, 0x000000, ((600 - height) / 600) / 2);
		if (pos.x >= 0 && pos.x < 1000)
			my_mlx_pixel_put(zone->mlx, pos.x, pos.y, color);
		index.y += y_step;
		pos.y++;
	}
}

int	draw3d(float height, t_coll coll, int x, t_zone *zone)
{
	int		y;
	float	offset;

	offset = 0;
	if (height > 1000)
	{
		offset = (height - 1000);
		height = 1000;
	}
	y = (1000 - height) / 2;
	if (coll.dir & 1)
		fill_with_texture(&zone->texture[0], new_pos(x, y, 0),
			zone, textures_index(coll.pos, offset, height, 1));
	else if (coll.dir & 2)
		fill_with_texture(&zone->texture[1], new_pos(x, y, 0),
			zone, textures_index(coll.pos, offset, height, 1));
	else if (coll.dir & 4)
		fill_with_texture(&zone->texture[2], new_pos(x, y, 0),
			zone, textures_index(coll.pos, offset, height, 0));
	else if (coll.dir & 8)
		fill_with_texture(&zone->texture[3], new_pos(x, y, 0),
			zone, textures_index(coll.pos, offset, height, 0));
	return (0);
}

double	get_draw_distance(t_pos pos, double rot, t_pos pixel, double angle)
{
	double	d_x;
	double	d_y;
	double	sin_result;
	double	cos_result;
	double	dist;

	d_x = (int)fabs(pos.x - pixel.x);
	d_y = (int)fabs(pos.y - pixel.y);
//	printf("%f = draw->pos_x\n", pos->x);
	cos_result = fabs(cos(rot * M_PI / 180.0));
	sin_result = fabs(sin(rot * M_PI / 180.0));
	dist = d_x * cos_result + d_y * sin_result;
	dist = dist * cos(rot * M_PI / 180.0);
	dist = (50 * 1000) / dist;
//	printf("%f = dist\n", dist);
	return (dist);
}

int	is_in_bound(double x, double y, t_zone *zone)
{
	if ((int)x >= zone->width * 32 || x < 0.0)
		return (0);
	if ((int)y >= zone->height * 32 || y < 0.0)
		return (0);
	return (1);
}

t_coll	new_collider(t_pos pos, int type, int dir)
{
	t_coll	collider;

	collider.pos = pos;
	collider.type = type;
	collider.dir = dir;
	return (collider);
}

int	check_inter_y(t_pos inter, t_draw *draw)
{
	int		i_x;
	int		i_y;

	i_x = (int)inter.x / 32.0;
	i_y = (int)inter.y / 32.0;
	if (i_x < 0 || i_y < 0 || i_x >= draw->zone->width
		|| i_y >= draw->zone->height)
		return (1);
	if (draw->zone->matrice_help[i_x + (i_y * draw->zone->width)] == '1')
		return (1);
	if (i_y > 0 && draw->zone->matrice_help[i_x
			+ ((i_y - 1) * draw->zone->width)] == '1')
		return (1);
	return (0);
}

int	check_inter_x(t_pos inter, t_draw *draw)
{
	int		i_x;
	int		i_y;

	i_x = (int)inter.x / 32.0;
	i_y = (int)inter.y / 32.0;
	if (i_x < 0 || i_y < 0 || i_x >= draw->zone->width
		|| i_y >= draw->zone->height)
		return (1);
	if (draw->zone->matrice_help[i_x + (i_y * draw->zone->width)] == '1')
		return (1);
	if (i_x > 0 && draw->zone->matrice_help[i_x - 1
			+ (i_y * draw->zone->width)] == '1')
		return (1);
	return (0);
}

t_pos	increment_pos(t_pos inter, int xy, int side, double rot)
{
	int	sign;

	sign = 0;
	if (side == 1 || side == 8)
		sign = 1;
	else if (side == 2 || side == 4)
		sign = -1;
	if (xy == 'y')
	{
		inter.x += (32.0 / tan(rot * M_PI / 180.0)) * sign;
		inter.y += -32.0 * sign;
	}
	else
	{
		inter.x += 32.0 * sign;
		inter.y += (-32.0 * tan(rot * M_PI / 180.0)) * sign;
	}
	return (inter);
}

int	parse_s(int side, int xy)
{
	if (xy == 'y')
	{
		if (side == 5 || side == 4)
			return (1);
		else
			return (2);
	}
	else if (xy == 'x')
	{
		if (side == 5 || side == 7)
			return (8);
		else
			return (4);
	}
	return (0);
}

t_coll	check_dir(t_pos inter_y, t_pos inter_x, int side, t_draw *draw)
{
	int	x;
	int	y;

	x = draw->pos_x;
	y = draw->pos_y;
	while (1)
	{	
		if ((pow(inter_y.x - x, 2) + pow(inter_y.y - y, 2))
			< (pow(inter_x.x - x, 2) + pow(inter_x.y - y, 2)))
		{
			if (check_inter_y(inter_y, draw) == 1)
				return (new_collider(inter_y, 0, parse_s(side, 'y')));
			else
				inter_y = increment_pos(inter_y, 'y',
						parse_s(side, 'y'), draw->rot);
		}
		else
		{
			if (check_inter_x(inter_x, draw) == 1)
				return (new_collider(inter_x, 0, parse_s(side, 'x')));
			else
				inter_x = increment_pos(inter_x, 'x',
						parse_s(side, 'x'), draw->rot);
		}
	}
	return (new_collider(new_pos(0, 0, 0), 0, 0));
}

t_coll	check_intersections(double x, double y, t_draw *draw)
{
	t_pos	inter_y_n;
	t_pos	inter_y_s;
	t_pos	inter_x_e;
	t_pos	inter_x_w;

	inter_y_n.x = x + ((fmod(y, 32.0))
			/ tan(draw->rot * M_PI / 180.0));
	inter_y_n.y = y - (fmod(y, 32.0));
	inter_y_s.x = x - (32.0 - (fmod(y, 32.0)))
		/ tan(draw->rot * M_PI / 180.0);
	inter_y_s.y = y + (32.0 - (fmod(y, 32.0)));
	inter_x_e.x = x - (fmod(x, 32.0)) + 32.0;
	inter_x_e.y = y - ((32.0 - (fmod(x, 32.0)))
			* tan(tan(draw->rot * M_PI / 180.0)));
	inter_x_w.x = x - (fmod(x, 32.0));
	inter_x_w.y = y + ((32.0 - (32.0 - (fmod(x, 32.0))))
			* tan(draw->rot * M_PI / 180.0));
	if (draw->rot >= 0 && draw->rot <= 90)
		return (check_dir(inter_y_n, inter_x_e, 5, draw));
	else if (draw->rot >= 90 && draw->rot <= 180)
		return (check_dir(inter_y_n, inter_x_w, 4, draw));
	else if (draw->rot >= 180 && draw->rot <= 270)
		return (check_dir(inter_y_s, inter_x_w, 6, draw));
	else if (draw->rot >= 270 && draw->rot <= 360)
		return (check_dir(inter_y_s, inter_x_e, 7, draw));
	return (new_collider(new_pos(0, 0, 0), 0, 0));
}

void	dda_init2(t_draw *draw, t_zone *zone)
{
	draw->line_height = (int)(1000 / draw->perp_wall_dist);
	draw->draw_start = -draw->line_height / 2 + 1000 / 2;
	if (draw->draw_start < 0)
		draw->draw_start = 0;
	draw->draw_end = draw->line_height / 2 + 1000 / 2;
	if (draw->draw_end >= 1000)
		draw->draw_end = 1000 - 1;
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
		if (zone->matr_int[draw->map_x][draw->map_y] > 0)
			draw->hit = 1;
	}
}

void	step(t_draw *draw, t_zone *zone)
{
	if (draw->ray_dir_x < 0)
	{
		draw->step_x = -1;
		draw->side_dist_x = (draw->pos_x - draw->map_x) * draw->delta_dist_x;
	}
	else
	{
		draw->step_x = 1;
		draw->side_dist_x = (draw->map_x + 1.0 - draw->pos_x)
			* draw->delta_dist_x;
	}
	if (draw->ray_dir_y < 0)
	{
		draw->step_y = -1;
		draw->side_dist_y = (draw->pos_y - draw->map_y) * draw->delta_dist_y;
	}
	else
	{
		draw->step_y = 1;
		draw->side_dist_y = (draw->map_y + 1.0 - draw->pos_y)
			* draw->delta_dist_y;
	}
}

void	dda_init(t_draw *draw, t_zone *zone, int x)
{
	draw->camera_x = 2 * x / (double)1000 - 1;
	draw->ray_dir_x = draw->dir_x + draw->plane_x * draw->camera_x;
	draw->ray_dir_y = draw->dir_y + draw->plane_y * draw->camera_x;
	if (draw->ray_dir_x == 0)
		draw->delta_dist_x = 1e30;
	else
		draw->delta_dist_x = fabs(1 / draw->ray_dir_x);
	if (draw->ray_dir_y == 0)
		draw->delta_dist_y = 1e30;
	else
		draw->delta_dist_y = fabs(1 / draw->ray_dir_y);
	draw->map_x = (int)draw->pos_x;
	draw->map_y = (int)draw->pos_y;
	draw->hit = 0;
}

void	dda(t_draw *draw, t_zone *zone)
{
	int			x;
	double		height;
	double		base_rot;
	t_coll		coll;

	x = -1;
	coll = new_collider(new_pos(0, 0, 0), 0, 0);
	draw_background(zone);
	draw_other(draw, zone);
	base_rot = draw->rot;
	draw->rot -= 30;
	while (++x < 1000)
	{
	//	printf("qwe\n");
		dda_init(draw, zone, x);
		if (draw->rot >= 360)
			draw->rot = fmod(draw->rot, 360);
		if (draw->rot < 0)
			draw->rot = 360.0 + draw->rot;
		coll = check_intersections(zone->player->pos.x, zone->player->pos.y, draw);
		if (is_in_bound(coll.pos.x, coll.pos.y, zone))
		{
			height = get_draw_distance(draw->zone->player->pos, draw->rot, coll.pos, base_rot - draw->rot);
			draw->line_height = height;
			draw3d(height, coll, 1000 - x, zone);
		}
	//	step(draw, zone);
	//	while_hit(draw, zone);
	//	if (draw->side == 0)
	//		draw->perp_wall_dist = (draw->side_dist_x - draw->delta_dist_x);
	//	else
	//		draw->perp_wall_dist = (draw->side_dist_y - draw->delta_dist_y);
	//	dda_init2(draw, zone);
	//	draw_texture(draw, zone, x);
	}
	mlx_put_image_to_window(zone->mlx->mlx_ptr,
		zone->mlx->mlx_win, zone->mlx->mlx_img, 0, 0);
}
