/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:50:14 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/24 15:20:01 by tconwy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct	s_zone
{
	int		image_y;
	int		image_x;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
	char	**matrice;
	char	*matrice_help;
	int		**matr_int;
	int		height;
	int		width;
}				t_zone;

// typedef struct	s_map
// {
// 	int		height;
// 	int		width;
// }				t_map;

void	gnl_help(t_zone *zone, int file);
int		parce_map(t_zone *zone);
void	free_string1(char **u);
void	map_int(t_zone *zone);

#endif