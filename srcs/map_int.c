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

t_rgb	new_rgb(int r, int g, int b)
{
	t_rgb	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

int	color_valid_rgb(t_rgb rgb)
{
	if (rgb.r > 255 || rgb.r < 0)
		return(0);
	if (rgb.g > 255 || rgb.g < 0)
		return (0);
	if (rgb.b > 255 || rgb.b < 0)
		return (0);
	return (1);
}

void	*array_clear(void **ptr, void *(f)(void *))
{
	while (ptr && *ptr && f)
	{
		*ptr = f(*ptr);
		ptr++;
	}
	return (NULL);
}

void	*free_array(void **ptr, void *(f)(void *))
{
	int	a;

	a = 0;
	if (ptr == NULL)
		return (NULL);
	if (ptr != NULL && ptr[a] != NULL)
		array_clear(ptr, f);
	free(ptr);
	return (NULL);
}

int	init_color(t_rgb rgb)
{
	int	color_int;

	color_int = rgb.r << 16 | rgb.g << 8 | rgb.b;
	return (color_int);
}

int pars_f_c(t_zone *zone, char *colors, char id)
{
	t_rgb	rgb;
	char	**str;
	int		error;

	error = 0;
	while (*colors, ' ')
		colors++;
	str = ft_split(colors, ',');
	if (ft_array_size((void **)str) != 3)
		error = 10;
	else
	{
		rgb = new_rgb(ft_atoi(str[0]), ft_atoi(str[1]), ft_atoi(str[2]));
		if (!color_valid_rgb(rgb))
			error = 10;
	}
	free_array((void **)str, free);
	if (error)
		return (0);
	if (id = 'F')
		zone->floor = init_color(rgb);
	else
		zone->ceiling = init_color(rgb);
	return (1);
}

int	parse_identifier(t_zone *zone)
{
	int	valid;

	valid = -1;
	valid = pars_texture(zone->no, 0, zone);
	valid = pars_texture(zone->so, 1, zone);
	valid = pars_texture(zone->we, 2, zone);
	valid = pars_texture(zone->ea, 3, zone);
	valid = parse_f_c(zone, zone->f, 'F');
	valid = parse_f_c(zone, zone->c, 'C');
	if (valid == -1)
		return (0);
	return (valid);
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
			{
				zone->pos_y = y;
				zone->pos_x = x;
				zone->matr_int[y][x] = 3;
			}
			x++;
		}
		y++;
	}
	create_window(zone->mlx);
	if (parse_identifier(zone) == 0)
		exit (1);
}