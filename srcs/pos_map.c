#include	"../cub3d.h"

int	parse_is_player(char c, t_player *player)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (c == 'N')
			player->rot = 90;
		if (c == 'S')
			player->rot = 270;
		if (c == 'W')
			player->rot = 180;
		if (c == 'E')
			player->rot = 0;
		return (1);
	}
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
	else if (parse_is_player(zone->matrice_help[x + y * zone->width], zone->player))
	{
		printf("\n%f = rot123\n", zone->player->rot);
		// zone->player->pos.x = x * 32.0 + (32.0 / 2);
		// zone->player->pos.y = y * 32.0 + (32.0 / 2);
		printf ("\n%f = player->pos.x\n", zone->player->pos.x);
		printf ("\n%f = player->pos.y\n", zone->player->pos.y);
		if (*player_found > 0 || !parse_floor(zone, x, y, ' '))
			return (0);
		*player_found = 1;
		printf("\n%f = rot0\n", zone->player->rot);
	}
	return (1);
}
