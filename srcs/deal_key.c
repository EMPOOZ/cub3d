/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:19:45 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/08 19:41:08 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	press_up(int key, t_zone *zone)
{
	if (zone->matr_int[(int)(zone->draw->pos_x + zone->draw->dir_x
			* 0.5)][(int)(zone->draw->pos_y)] == 0)
		zone->draw->pos_x += zone->draw->dir_x * 0.3;
	if (zone->matr_int[(int)(zone->draw->pos_x)][(int)(zone->draw->pos_y
			+ zone->draw->dir_y * 0.5)] == 0)
		zone->draw->pos_y += zone->draw->dir_y * 0.3;
}

void	press_down(int key, t_zone *zone)
{
	if (zone->matr_int[(int)(zone->draw->pos_x - zone->draw->dir_x
			* 0.5)][(int)(zone->draw->pos_y)] == 0)
		zone->draw->pos_x += zone->draw->dir_x * (-0.3);
	if (zone->matr_int[(int)(zone->draw->pos_x)][(int)(zone->draw->pos_y
			- zone->draw->dir_y * 0.5)] == 0)
		zone->draw->pos_y += zone->draw->dir_y * (-0.3);
}

void	press_left(int key, t_zone *zone)
{
	if (zone->matr_int[(int)(zone->draw->pos_x - zone->draw->plane_x
			* 0.5)][(int)(zone->draw->pos_y)] == 0)
		zone->draw->pos_x += zone->draw->plane_x * (-0.3);
	if (zone->matr_int[(int)(zone->draw->pos_x)][(int)(zone->draw->pos_y
			- zone->draw->plane_y * 0.5)] == 0)
		zone->draw->pos_y += zone->draw->plane_y * (-0.3);
}

void	press_right(int key, t_zone *zone)
{
	if (zone->matr_int[(int)(zone->draw->pos_x + zone->draw->plane_x
			* 0.5)][(int)(zone->draw->pos_y)] == 0)
		zone->draw->pos_x += zone->draw->plane_x * 0.3;
	if (zone->matr_int[(int)(zone->draw->pos_x)][(int)(zone->draw->pos_y
			+ zone->draw->plane_y * 0.5)] == 0)
		zone->draw->pos_y += zone->draw->plane_y * 0.3;
}

int	key_press(int key, t_zone *zone)
{
	if (key == 123 || key == 124)
		rotate(key, zone);
	if (key == 13)
		press_up(key, zone);
	if (key == 1)
		press_down(key, zone);
	if (key == 0)
		press_left(key, zone);
	if (key == 2)
		press_right(key, zone);
	if (key == 53)
		exit(1);
	return (key);
}
