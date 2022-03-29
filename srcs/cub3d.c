/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:29:18 by tconwy            #+#    #+#             */
/*   Updated: 2022/03/29 14:08:50 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_zone(t_zone *zone, int file)
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
	t_zone	*zone;

	zone = (t_zone *)malloc(sizeof(t_zone));
	zone->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	zone->matrice_help = NULL;
	if (argc != 2)
		return (0);
	file = open(argv[1], O_RDWR);
	create_window(zone->mlx);
	gnl_help(zone, file);
	if (parce_map(zone) == 0)
		return (1);
	map_int(zone);
	rendering(zone);
	mlx_loop(zone->mlx->mlx_ptr);
	free_zone(zone, file);
	return (0);
}
