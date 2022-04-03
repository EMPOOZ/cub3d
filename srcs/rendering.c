/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:43:32 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/03 15:46:49 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_init(t_draw *draw, t_zone *zone)
{
	draw->pos_x = (double)zone->pos_x;
	draw->pos_y = (double)zone->pos_y;
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

void	player_init(t_player *player)
{
	player->pos.x = 0;
	player->pos.y = 0;
	player->rot = 0;
}

int	rotate_player(t_player *player, double rot)
{
	if (player->rot + rot >= 360)
		player->rot = fmod((player->rot + rot), (double)360);
	else if (player->rot + rot < 0)
		player->rot = 360 - fmod(fabs((player->rot + rot)), (double)360);
	else
		player->rot += rot;
	return (player->rot);
}

t_pos	move_pos(t_pos pos, double rot, double dist, int dir)
{
	t_pos	new_pos;

	if (dir)
		rot += 90;
	new_pos.x = pos.x + dist * cos(rot * M_PI / 180.0);
	new_pos.y = pos.y + dist * -sin(rot * M_PI / 180.0);
	new_pos.z = pos.z + 0;
	return (new_pos);
}

int	change_player_pos(t_player *player, double vel, int dir)
{
	t_pos	pos;
	t_pos	new_pos;

	pos.x = player->pos.x;
	pos.y = player->pos.y;
	new_pos = move_pos(pos, player->rot, vel, dir);
	player->pos.x = new_pos.x;
	player->pos.y = new_pos.y;
	return (0);
}

void	move_player(t_player *p)
{
	if (p->vel_u + p->vel_d && p->vel_r + p->vel_l)
	{
		change_player_pos(p, (p->vel_u + p->vel_d) * 0.707, 0);
		change_player_pos(p, (p->vel_r + p->vel_l) * 0.707, 1);
	}
	else
	{
		if (p->vel_u + p->vel_d)
			change_player_pos(p, p->vel_u + p->vel_d, 0);
		if (p->vel_r + p->vel_l)
			change_player_pos(p, p->vel_r + p->vel_l, 1);
	}
	if (p->turn_l + p->turn_r)
		rotate_player(p, p->turn_l + p->turn_r);
}

int	rendering(t_zone *zone)
{
	printf("%f = draw->pos_x123\n", zone->player->pos.x);
	move_player(zone->player);
	printf("%f = draw->pos_x\n", zone->player->pos.x);
	dda(zone->draw, zone);
	return (0);
}
