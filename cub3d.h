/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:50:14 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/21 17:50:14 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <gnl/get_next_line.h>
# include <libft/libft.h>

typedef	struct s_zone
{
	int		image_y;
	int		image_x;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*v;
	char	**matrice;
}				t_zone;

#endif