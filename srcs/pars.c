/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:53:02 by tconwy            #+#    #+#             */
/*   Updated: 2022/04/01 12:47:46 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parser4(char *str, t_zone *zone, int a)
{
	if (a >= 6)
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

int	parser3(char *str, t_zone *zone, int a)
{
	int		i[2];
	char	**str2;

	i[0] = 0;
	i[1] = 0;
	if (str[i[0]] == 'F')
	{
		str2 = ft_split(str, ' ');
		zone->f = ft_strdup(str2[1]);
		free_string1(str2);
		return (1);
	}
	else if (str[i[0]] == 'C')
	{
		str2 = ft_split(str, ' ');
		zone->c = ft_strdup(str2[1]);
		free_string1(str2);
		return (1);
	}
	else
		if (parser4(str, zone, a) == 1)
			return (1);
	return (0);
}

int	parser2(char *str, t_zone *zone, int a)
{
	int		i;
	char	**str2;

	i = 0;
	if (str[i] == 'W' && str[i + 1] == 'E')
	{
		str2 = ft_split(str, ' ');
		zone->we = ft_strdup(str2[1]);
		free_string1(str2);
		return (1);
	}
	else if (str[i] == 'E' && str[i + 1] == 'A')
	{
		str2 = ft_split(str, ' ');
		zone->ea = ft_strdup(str2[1]);
		free_string1(str2);
		return (1);
	}
	else
		if (parser3(str, zone, a) == 1)
			return (1);
	return (0);
}

int	parser(char *str, t_zone *zone, int a)
{
	int		i;
	char	**str2;

	i = 0;
	if (str[i] == 'N' && str[i + 1] == 'O')
	{
		str2 = ft_split(str, ' ');
		zone->no = ft_strdup(str2[1]);
		free_string1(str2);
		return (1);
	}
	else if (str[i] == 'S' && str[i + 1] == 'O')
	{
		str2 = ft_split(str, ' ');
		zone->so = ft_strdup(str2[1]);
		free_string1(str2);
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
			if (parser(str, zone, a) == 0)
				exit(1);
			a++;
		}
	}
	free (str);
}
