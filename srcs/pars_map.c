#include "../cub3d.h"

int	parce_map_closed2(t_zone *zone, int y)
{
	int	x;

	if (y >= zone->height || y < 0)
	{
		ft_putstr_fd ("\n1\n", 1);
		return (0);
	}
	x = 0;
	while (zone->matrice_help[x + y * zone->width] == ' ')
		x++;
	if (zone->matrice_help[x + y *zone->width] != '1')
	{
		printf ("\n%c = el\n", zone->matrice_help[x + y * zone->width]);
		printf ("\n%d = y\n", y);
		printf ("\n%d = x\n", x);
		ft_putstr_fd ("\n2\n", 1);
		return (0);
	}
	x = zone->width - 1;
	while (zone->matrice_help[x + y * zone->width] == ' ')
		x--;
	if (zone->matrice_help[x + y * zone->width] != '1')
	{
		printf ("\n%c = el\n", zone->matrice_help[x + y * zone->width]);
		printf ("\n%d = y\n", y);
		printf ("\n%d = x\n", x);
		ft_putstr_fd ("\n3\n", 1);
		return (0);
	}
	return (1);
}

int	parce_map_closed1(t_zone *zone, int x)
{
	int	y;

	if (x >= zone->width || x < 0)
	{
		ft_putstr_fd ("\n4\n", 1);
		return (0);
	}
	y = 0;
	while (zone->matrice_help[x + y * zone->width] == ' ')
		y++;
	if (zone->matrice_help[x + y * zone->width] != '1')
	{
		ft_putstr_fd ("\n5\n", 1);
		return (0);
	}
	y = zone->height - 1;
	while (zone->matrice_help[x + y * zone->width] == ' ')
		y--;
	if (zone->matrice_help[x + y * zone->width] != '1')
	{
		ft_putstr_fd ("\n6\n", 1);
		return (0);
	}
	return (1);
}

int	parse_maphelp(t_zone *zone)
{
	int	i;

	i = 0;
	// // while (zone->matrice[i])
	// printf ("\n%s\n", zone->matrice_help);
	// printf ("\n%d = w\n", zone->width);
	i = 0;
	while (i < zone->height)
	{
		if (!parce_map_closed2(zone, i++))
			return (0);
	}
	i = 0;
	while (i < zone->width)
	{
		if (!parce_map_closed1(zone, i++))
			return(0);
	}
	return (1);
}

void re_parse_martrice(t_zone *zone)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < zone->height)
	{
		x = ft_strlen(zone->matrice[y]);
		while (x < zone->width)
		{
			zone->matrice[y] = ft_strjoin1(zone->matrice[y], " ");
			x++;
		}
		y++;
	}
}

int	parce_map(t_zone *zone)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	zone->matrice = ft_split(zone->matrice_help, '\n');
	while (zone->matrice[y])
	{
		x = 0;
		while (zone->matrice[y][x])
		{
			x++;
			if (zone->width < x)
				zone->width = x;
		}
		y++;
	}
	zone->height = y;
	re_parse_martrice(zone);
	y = 0;
	free (zone->matrice_help);
	zone->matrice_help = NULL;
	x = 0;
	while(x < zone->height)
	{
		zone->matrice_help = ft_strjoin1(zone->matrice_help, zone->matrice[x]);
		x++;
	}
	if (parse_maphelp(zone) == 0)
	{
		printf("\nkurva\n");
		return (0);
	}
	return(1);
}