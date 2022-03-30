/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:19:45 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/29 19:34:11 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	press_s(t_zone *zone, t_draw *draw)
{
	if (zone->matr_int[(int)(draw->pos_x - draw->dir_x * 1)][(int)draw->pos_x]
		== 1)
		draw->pos_x -= draw->dir_x * 1;
	if (zone->matr_int[(int)draw->pos_x][(int)(draw->pos_y - draw->dir_y * 1)]
		== 1)
		draw->pos_x -= draw->dir_x * 1;
	draw->pos_x -= draw->dir_x * 1;
}

void	press_w(t_zone *zone, t_draw *draw)
{
	if (zone->matr_int[(int)(draw->pos_x + draw->dir_x * 1)][(int)draw->pos_x]
		== 1)
		draw->pos_x -= draw->dir_x * 1;
	if (zone->matr_int[(int)draw->pos_x][(int)(draw->pos_y + draw->dir_y * 1)]
		== 1)
		draw->pos_x -= draw->dir_x * 1;
	draw->pos_x += draw->dir_x * 1;
}

void	press_a(t_draw *draw)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = draw->dir_x;
	old_plane_x = draw->plane_x;
	draw->dir_x = draw->dir_x * cos(1) - draw->dir_y * sin(1);
	draw->dir_y = old_dir_x * sin(1) + draw->dir_y * cos(1);
	draw->plane_x = draw->plane_x * cos(-1) - draw->plane_y * sin(1);
	draw->plane_y = old_plane_x * sin(1) + draw->plane_y * cos(1);
	printf("\nqwe\n");
}

void	press_d(t_draw *draw)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = draw->dir_x;
	old_plane_x = draw->plane_x;
	draw->dir_x = draw->dir_x * cos(-1) - draw->dir_y * sin(-1);
	draw->dir_y = old_dir_x * sin(-1) + draw->dir_y * cos(-1);
	draw->plane_x = draw->plane_x * cos(-1) - draw->plane_y * sin(-1);
	draw->plane_y = old_plane_x * sin(-1) + draw->plane_y * cos(-1);
	printf("\nqwe\n");
}

int	deal_key(int key, t_zone *zone)
{
	printf("%d\n", key);
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
	dda(zone->draw, zone);
	return (0);
}
