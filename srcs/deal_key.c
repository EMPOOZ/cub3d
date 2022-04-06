/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:19:45 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/05 19:40:39 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
/*
int	mouse_handler(int x, int y)
{
	static int	mouse_x = 0;
	static int	mouse_y = 0;

	if (mouse_x != x)
		rotate_player(&g_game.player, (mouse_x - x) * MOUSE_TURN);
	mouse_x = x;
	mouse_y = y;
	return (0);
}
*/
int	key_press(int key, t_zone *zone)
{
	double	modifier;
	double	old_dir_x;
	double	old_plane_x;

	modifier = ((double)1000 * (double)1000) / 1000000.0;
	if (key == 123)
	{	
		old_dir_x = zone->draw->dir_x;
		zone->draw->dir_x = zone->draw->dir_x * cos(0.25)
			- zone->draw->dir_y * sin(0.25);
		zone->draw->dir_y = old_dir_x * sin(0.25)
			+ zone->draw->dir_y * cos(0.25);
		old_plane_x = zone->draw->plane_x;
		zone->draw->plane_x = zone->draw->plane_x * cos(0.25)
			- zone->draw->plane_y * sin(0.25);
		zone->draw->plane_y = old_plane_x * sin(0.25)
			+ zone->draw->plane_y * cos(0.25);
	}
	if (key == 124)
	{
		old_dir_x = zone->draw->dir_x;
		zone->draw->dir_x = zone->draw->dir_x * cos(-0.25)
			- zone->draw->dir_y * sin(-0.25);
		zone->draw->dir_y = old_dir_x * sin(-0.25)
			+ zone->draw->dir_y * cos(-0.25);
		old_plane_x = zone->draw->plane_x;
		zone->draw->plane_x = zone->draw->plane_x * cos(-0.25)
			- zone->draw->plane_y * sin(-0.25);
		zone->draw->plane_y = old_plane_x * sin(-0.25)
			+ zone->draw->plane_y * cos(-0.25);
	}
	if (key == 13)
	{
		if (zone->matr_int[(int)(zone->draw->pos_x + zone->draw->dir_x * 0.25)][(int)(zone->draw->pos_y)] == 0)
			zone->draw->pos_x += zone->draw->dir_x * 0.25;
		if (zone->matr_int[(int)(zone->draw->pos_x)][(int)(zone->draw->pos_y + zone->draw->dir_y * 0.25)] == 0)
			zone->draw->pos_y += zone->draw->dir_y * 0.25;
	}
	if (key == 1)
		zone->player->vel_d = -8 * modifier;
	if (key == 0)
	{
		if (zone->matr_int[(int)(zone->draw->pos_x + zone->draw->dir_x * 0.25)][(int)(zone->draw->pos_y)] == 0)
			zone->draw->pos_x += zone->draw->dir_x * (-0.25);
		if (zone->matr_int[(int)(zone->draw->pos_x)][(int)(zone->draw->pos_y + zone->draw->dir_y * 0.25)] == 0)
			zone->draw->pos_y += zone->draw->dir_y * (-0.25);
	}
	if (key == 2)
		zone->player->vel_r = -8 * modifier;
	return (key);
}

int	key_release(int key, t_zone *zone)
{
	if (key == 13)
		zone->player->vel_u = 0;
	if (key == 0)
		zone->player->vel_l = 0;
	if (key == 1)
		zone->player->vel_d = 0;
	if (key == 2)
		zone->player->vel_r = 0;
	if (key == 123)
		zone->player->turn_l = 0;
	if (key == 124)
		zone->player->turn_r = 0;
	if (key == 53)
		exit(1);
	return (key);
}

int	quit_handler(void)
{
	exit(1);
	return (0);
}
