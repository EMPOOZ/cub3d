/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:29:18 by tconwy            #+#    #+#             */
/*   Updated: 2022/04/04 15:15:21 by rmicheli         ###   ########.fr       */
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
	t_draw	*draw;

	zone = (t_zone *)malloc(sizeof(t_zone));
	zone->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	zone->player = (t_player *)malloc(sizeof(t_player));
	player_init(zone->player);
	zone->matrice_help = NULL;
	if (argc != 2)
		return (0);
	file = open(argv[1], O_RDWR);
	create_window(zone->mlx);
	gnl_help(zone, file);
	if (parce_map(zone) == 0)
		return (1);
	map_int(zone);
	draw = (t_draw *)malloc(sizeof(t_draw));
	zone->draw = draw;
	draw_init(draw, zone);
	mlx_hook(zone->mlx->mlx_win, 2, 1L << 0, key_press, zone);
	mlx_hook(zone->mlx->mlx_win, 3, 1L << 1, key_release, zone);
	mlx_loop_hook(zone->mlx->mlx_ptr, rendering, zone);
	mlx_loop(zone->mlx->mlx_ptr);
	free_zone(zone, file);
	return (0);
}
