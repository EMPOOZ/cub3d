/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:19:30 by rmicheli          #+#    #+#             */
/*   Updated: 2022/04/07 13:19:31 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../cub3d.h"

int	parse_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	parse_wall(t_zone *zone, int x, int y)
{
	char	*t;
	int		w;
	int		h;

	w = zone->width;
	h = zone->height;
	t = zone->matrice_help;
	if (x != 0 && t[x - 1 + y * w] != '1'
		&& x != 0 && t[x - 1 + y * w] != ' ')
		return (0);
	if (x < w - 1 && t[x + 1 + y * w] != '1'
		&& x < w - 1 && t[x + 1 + y * w] != ' ')
		return (0);
	if (y != 0 && t[x + (y - 1) * w] != '1'
		&& y != 0 && t[x + (y - 1) * w] != ' ')
		return (0);
	if (y < h && t[x + (y + 1) * w] != '1'
		&& y < h && t[x + (y + 1) * w] != ' ')
		return (0);
	return (1);
}

// Check if the tile has any EMPTY around it
int	parse_floor(t_zone *zone, int x, int y, int compare)
{
	char	*tiles;

	tiles = zone->matrice_help;
	if (x != 0 && tiles[x - 1 + y * zone->width] == compare)
		return (0);
	if (x < zone->width - 1 && tiles[x + 1 + y * zone->width] == compare)
		return (0);
	if (y != 0 && tiles[x + (y - 1) * zone->width] == compare)
		return (0);
	if (y < zone->height - 1 && tiles[x + (y + 1) * zone->width] == compare)
		return (0);
	return (1);
}

// Check if the code (WALL, FLOOR, etc.) at (x, y) location is valid.
int	pos_map(t_zone *zone, int x, int y, int *player_found)
{
	if (zone->matrice_help[x + y * zone->width] == '1')
	{
		if (parse_wall(zone, x, y))
			zone->matrice_help[x + y * zone->width] = ' ';
	}
	else if (zone->matrice_help[x + y * zone->width] == '0')
	{
		if (!parse_floor(zone, x, y, ' '))
			return (0);
	}
	else if (parse_is_player(zone->matrice_help[x + y * zone->width]))
	{
		if (*player_found > 0 || !parse_floor(zone, x, y, ' '))
			return (0);
		*player_found = 1;
	}
	return (1);
}
