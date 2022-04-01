/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:19:45 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/01 13:52:23 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	press_s(t_zone *zone, t_draw *draw)
{
	if (zone->matr_int[(int)(draw->pos_x - draw->dir_x * 0.25)][(int)draw->pos_x]
		== 0)
		draw->pos_x -= draw->dir_x * 0.25;
	if (zone->matr_int[(int)draw->pos_x][(int)(draw->pos_y - draw->dir_y * 0.25)]
		== 0)
		draw->pos_y -= draw->dir_y * 0.25;
}

void	press_w(t_zone *zone, t_draw *draw)
{
	if (zone->matr_int[(int)(draw->pos_x + draw->dir_x * 0.25)][(int)draw->pos_x]
		== 0)
		draw->pos_x += draw->dir_x * 0.25;
	if (zone->matr_int[(int)draw->pos_x][(int)(draw->pos_y + draw->dir_y * 0.25)]
		== 0)
		draw->pos_y += draw->dir_y * 0.25;
}

void	press_a(t_draw *draw)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = draw->dir_x;
	old_plane_x = draw->plane_x;
	draw->dir_x = draw->dir_x * cos(0.5) - draw->dir_y * sin(0.5);
	draw->dir_y = old_dir_x * sin(0.5) + draw->dir_y * cos(0.5);
	draw->plane_x = draw->plane_x * cos(0.5) - draw->plane_y * sin(0.5);
	draw->plane_y = old_plane_x * sin(0.5) + draw->plane_y * cos(0.5);
	printf("\nqwe\n");
}

void	press_d(t_draw *draw)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = draw->dir_x;
	old_plane_x = draw->plane_x;
	draw->dir_x = draw->dir_x * cos(-0.5) - draw->dir_y * sin(-0.5);
	draw->dir_y = old_dir_x * sin(-0.5) + draw->dir_y * cos(-0.5);
	draw->plane_x = draw->plane_x * cos(-0.5) - draw->plane_y * sin(-0.5);
	draw->plane_y = old_plane_x * sin(-0.5) + draw->plane_y * cos(-0.5);
	printf("\nqwe\n");
}

int	deal_key(int key, t_zone *zone)
{
	if (key == 1)
		press_s(zone, zone->draw);
	if (key == 13)
		press_w(zone, zone->draw);
	if (key == 2)
		press_d(zone->draw);
	if (key == 0)
		press_a(zone->draw);
	if (key == 53)
		exit(0);
	return (0);
}
