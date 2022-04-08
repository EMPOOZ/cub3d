/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:29:18 by tconwy            #+#    #+#             */
/*   Updated: 2022/04/08 19:43:33 by rmicheli         ###   ########.fr       */
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

int	check_cub(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.')
		i++;
	if (ft_strncmp(str + i, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	exit_f(void)
{
	exit(1);
	return(0);
}

void	game_play(t_zone *zone, t_draw *draw, int file)
{
	draw_init(draw, zone);
	mlx_hook(zone->mlx->mlx_win, 2, 1L << 0, key_press, zone);
	mlx_hook(zone->mlx->mlx_win, 17, 0, exit_f, NULL);
	mlx_loop_hook(zone->mlx->mlx_ptr, rendering, zone);
	mlx_loop(zone->mlx->mlx_ptr);
	free_zone(zone, file);
}

int	main(int argc, char **argv)
{
	int		file;
	t_zone	*zone;
	t_draw	*draw;

	zone = (t_zone *)malloc(sizeof(t_zone));
	zone->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	zone->matrice_help = NULL;
	if (argc != 2)
		return (0);
	if (check_cub(argv[1]) == 0)
	{
		printf("no cub\n");
		return (0);
	}
	file = open(argv[1], O_RDWR);
	create_window(zone->mlx);
	gnl_help(zone, file);
	if (parce_map(zone) == 0)
		return (1);
	map_int(zone);
	draw = (t_draw *)malloc(sizeof(t_draw));
	zone->draw = draw;
	game_play(zone, draw, file);
	return (0);
}
