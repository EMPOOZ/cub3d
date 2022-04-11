/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 13:37:47 by tconwy            #+#    #+#             */
/*   Updated: 2022/04/11 15:35:43 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exit_error(char *error)
{
	printf("%s", error);
	exit(1);
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
	zone->matr_int = NULL;
	if (!zone || !zone->mlx || !draw)
		return (0);
	init_img(zone);
	if (create_window(zone->mlx) == 0)
		return (0);
	zone->draw = draw;
	zone->matrice_help = NULL;
	return (1);
}
