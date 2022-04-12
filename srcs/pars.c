/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:53:02 by tconwy            #+#    #+#             */
/*   Updated: 2022/04/11 19:26:37 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parser4(char *str, t_zone *zone, int *a)
{
	if (*a >= 6)
	{
		if (zone->matrice_help == NULL)
			zone->matrice_help = ft_strdup(str);
		else
			zone->matrice_help = ft_strjoin1(zone->matrice_help, str);
	}
	else
		return (0);
	return (1);
}

int	parser3(char *str, t_zone *zone, int *a)
{
	char	**str2;

	if (str[0] == 'F' && zone->f == NULL)
	{
		str2 = ft_split(str, ' ');
		zone->f = ft_strdup(str2[1]);
		free_string1(str2);
		(*a)++;
		return (1);
	}
	else if (str[0] == 'C' && zone->c == NULL)
	{
		str2 = ft_split(str, ' ');
		zone->c = ft_strdup(str2[1]);
		free_string1(str2);
		(*a)++;
		return (1);
	}
	else
		if (parser4(str, zone, a) == 1)
			return (1);
	return (0);
}

int	parser2(char *str, t_zone *zone, int *a)
{
	char	**str2;

	if (str[0] == 'W' && str[1] == 'E' && zone->we == NULL)
	{
		str2 = ft_split(str, ' ');
		zone->we = ft_strdup(str2[1]);
		free_string1(str2);
		(*a)++;
		return (1);
	}
	else if (str[0] == 'E' && str[1] == 'A' && zone->ea == NULL)
	{
		str2 = ft_split(str, ' ');
		zone->ea = ft_strdup(str2[1]);
		free_string1(str2);
		(*a)++;
		return (1);
	}
	else
		if (parser3(str, zone, a) == 1)
			return (1);
	return (0);
}

int	parser(char *str, t_zone *zone, int *a)
{
	char	**str2;

	if (str[0] == 'N' && str[1] == 'O' && zone->no == NULL)
	{
		str2 = ft_split(str, ' ');
		zone->no = ft_strdup(str2[1]);
		free_string1(str2);
		(*a)++;
		return (1);
	}
	else if (str[0] == 'S' && str[1] == 'O' && zone->so == NULL)
	{
		str2 = ft_split(str, ' ');
		zone->so = ft_strdup(str2[1]);
		free_string1(str2);
		(*a)++;
		return (1);
	}
	else
		if (parser2(str, zone, a) == 1)
			return (1);
	return (0);
}

void	gnl_help(t_zone *zone, int file)
{
	char	*str;
	int		a;

	a = 0;
	str = NULL;
	str = malloc(sizeof(char));
	str[0] = '\0';
	while (str != NULL)
	{
		free (str);
		str = get_next_line(file);
		if (str == NULL)
			break ;
		if (ft_strncmp(str, "\n", 1) != 0)
		{
			if (parser(str, zone, &a) == 0)
			{
				printf("ERROR\n");
				exit(1);
			}
		}
	}
	correct_map(zone);
	free (str);
}
