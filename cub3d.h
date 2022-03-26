/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:49:21 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/26 15:31:46 by tconwy           ###   ########.fr       */
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
# include <mlx.h>

typedef struct s_draw
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	old_time;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	color;
	int		tex_num;
}				t_draw;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_img;
	void	*mlx_win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_zone
{
	int		pos_y;
	int		pos_x;
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
	int		floor;
	int		ceiling;
	t_img	texture[4];
	t_mlx	*mlx;
}				t_zone;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

void	*free_array(void **ptr, void *(f)(void *));
int		init_color(t_rgb rgb);
void	gnl_help(t_zone *zone, int file);
int		parce_map(t_zone *zone);
void	free_string1(char **u);
void	map_int(t_zone *zone);
void	create_window1(t_mlx *mlx);
void	*ft_free(void *ptr);
int		pars_texture(char *path, int side, t_zone *zone);
t_rgb	new_rgb(int r, int g, int b);
int		color_valid_rgb(t_rgb rgb);
void	*array_clear(void **ptr, void *(f)(void *));
int		array_s(void **str);
void	search_zone(t_zone *zone);

#endif
