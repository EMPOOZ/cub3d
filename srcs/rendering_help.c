/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:41:13 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/22 12:44:40 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_init(t_draw *draw, t_zone *zone)
{
	draw = (t_draw *)malloc(sizeof(*draw));
	draw->dir_x = -1;
	draw->dir_y = 0;
	draw->plane_x = 0;
	draw->plane_y = 0.66;
	draw->time = 0;
	draw->old_time = 0;
}
