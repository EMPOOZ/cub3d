/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:37:47 by tconwy            #+#    #+#             */
/*   Updated: 2022/04/09 17:13:39 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_img(t_img tex[4])
{
	if (tex[0].addr)
		free(tex[0].addr);
	if (tex[1].addr)
		free(tex[1].addr);
	if (tex[2].addr)
		free(tex[2].addr);
	if (tex[3].addr)
		free(tex[3].addr);
}

void	exit_free(t_zone *zone, t_draw *draw, char *error)
{
	if (zone->draw)
		free(zone->draw);
	if (zone->mlx)
	{
		free(zone->mlx->addr);
		free(zone->mlx);
	}
	if (zone)
	{
		free_img(zone->texture);
		free (zone);
	}
	if (draw->zone)
		free(draw->zone);
	if (draw)
		free(draw);
	printf("%s", error);
	exit(0);
}

void	init_img(t_zone *zone)
{
	zone->texture[0].addr = NULL;
	zone->texture[1].addr = NULL;
	zone->texture[2].addr = NULL;
	zone->texture[3].addr = NULL;
}

int	cub_init(t_zone *zone, t_draw *draw)
{
	zone->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	zone->draw = NULL;
	draw->zone = NULL;
	if (!zone || !zone->mlx || !draw)
		return (0);
	init_img(zone);
	create_window(zone->mlx);
	zone->draw = draw;
	zone->matrice_help = NULL;
	return (1);
}
