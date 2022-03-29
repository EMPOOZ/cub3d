/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:49:21 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/27 12:08:36 by rmicheli         ###   ########.fr       */
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

typedef struct s_texture_draw
{
	float	wall_x;
	int		tex_num;
	int		tex_x;
	int		tex_y;
	float	step;
	float	tex_pos;
}				t_texture_draw;

typedef struct s_draw
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
	float	time;
	float	old_time;
	float	camera_x;
	float	ray_dir_x;
	float	ray_dir_y;
	int		map_x;
	int		map_y;
	float	side_dist_x;
	float	side_dist_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	float	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	float	color;
}			t_draw;

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
}			t_zone;

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
void	create_window(t_mlx *mlx);
int		rendering(t_zone *zone);
void	dda(t_draw *draw, t_zone *zone);
void	draw_init(t_draw *draw, t_zone *zone);
void	draw_texture(t_draw *draw, t_zone *zone, int x);
void	verline(int x, t_draw *draw, t_zone *zone);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

#endif
