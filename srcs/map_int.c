#include "../cub3d.h"

void	pars_texture(t_zone *zone);

void map_int(t_zone *zone)
{
	int	y;
	int	x;

	y = 0;
	zone->matr_int = (int **)malloc(sizeof(int *) * zone->height);
	while (zone->matrice[y])
	{
		x = 0;
		zone->matr_int[y] = (int *)malloc(sizeof(int) * zone->width);
		while (zone->matrice[y][x])
		{
			if (zone->matrice[y][x] == '1')
				zone->matr_int[y][x] = 1;
			else if (zone->matrice[y][x] == ' ' || zone->matrice[y][x] == '0')
				zone->matr_int[y][x] = 0;
			else if (zone->matrice[y][x] == 'W')
				zone->matr_int[y][x] = 3;
			x++;
		}
		y++;
	}
	pars_texture(zone);
}