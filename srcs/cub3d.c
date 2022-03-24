/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:29:18 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/24 15:19:14 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void free_zone(t_zone *zone, int file)
{
	free (zone->ea);
	free (zone->f);
	free (zone->c);
	free (zone->no);
	free (zone->so);
	free (zone->we);
	free_string1(zone->matrice);
	free (zone->matrice_help);
	close(file);
}

int	main(int argc, char **argv)
{
	int		file;
	t_zone	zone;

	zone.matrice_help = NULL;
	if (argc != 2)
		return (0);
	file = open(argv[1], O_RDWR);
	gnl_help(&zone, file);
	if (parce_map(&zone) == 0)
		return(1);
	map_int(&zone);
	free_zone(&zone, file);
	return (0);
}

