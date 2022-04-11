/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:12:46 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/10 19:43:37 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_zone *zone)
{
	double	old_dir_x;
	double	old_plane_x;

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

void	rotate_right(t_zone *zone)
{
	double	old_dir_x;
	double	old_plane_x;

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

void	rotate(int key, t_zone *zone)
{
	printf("%d = key\n %c = char\n", key, zone->c1);
	if ((key == 123 && (zone->c1 == 'N' || zone->c1 == 'S')) || (key == 124 && (zone->c1 == 'W' || zone->c1 == 'E')))
		rotate_left(zone);
	if ((key == 124 && (zone->c1 == 'N' || zone->c1 == 'S'))
		|| (key == 123 && (zone->c1 == 'W' || zone->c1 == 'E')))
		rotate_right(zone);
}
