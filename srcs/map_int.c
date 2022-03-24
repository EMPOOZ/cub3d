#include "../cub3d.h"

int	pars_texture(char *path, int side, t_zone *zone)
{
	t_img	*img;

	while (*path == ' ')
		path++;
	img = &zone->texture[side];
	img->img = mlx_xpm_file_to_image(zone->mlx->mlx_win,
			path, &img->line_length, &img->height);
	if (!img->img)
		return (0);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	if (!img->addr)
		return (0);
	return (1);
}



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
	create_window(zone->mlx);
	pars_texture(zone);
}