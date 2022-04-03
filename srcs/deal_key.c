/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:19:45 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/03 15:50:53 by tconwy           ###   ########.fr       */
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

	modifier = ((double)1000 * (double)1000) / 1000000.0;
	if (key == 123)
		zone->player->turn_l = 8 * modifier;
	if (key == 124)
		zone->player->turn_r = -8 * modifier;
	if (key == 13)
		zone->player->vel_u = 8 * modifier;
	if (key == 1)
		zone->player->vel_d = -8 * modifier;
	if (key == 0)
		zone->player->vel_l = 8 * modifier;
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
