/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:47:37 by tconwy            #+#    #+#             */
/*   Updated: 2022/04/08 19:14:04 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include	<stdarg.h>
# include	<stdio.h>
# include	<limits.h>
# include	<stddef.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<math.h>
# include	<complex.h>
# include	<fcntl.h>
# include	<mlx.h>
# include	"gnl/get_next_line.h"
# include	"libft/libft.h"

typedef struct s_draw		t_draw;

typedef struct s_floor_and_celing
{
	float	ray_dir_x0;
	float	ray_dir_y0;
	float	ray_dir_x1;
	float	ray_dir_y1;
	int		p;
	float	pos_z;
	float	row_distance;
	float	floor_step_x;
	float	floor_step_y;
	float	floor_x;
	float	floor_y;
	int		cell_x;
	int		cell_y;
	int		tx;
	int		ty;
	int		floor_tex;
	int		ceiling_tex;
	int		color;
}				t_floor_and_celing;

typedef struct s_texture_draw
{
	double	wall_x;
	int		tex_num;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}				t_texture_draw;

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

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_zone
{
	int			pos_y;
	int			pos_x;
	int			image_y;
	int			image_x;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*f;
	char		*c;
	char		**matrice;
	char		*matrice_help;
	int			**matr_int;
	int			height;
	int			width;
	int			floor;
	int			ceiling;
	t_draw		*draw;
	t_img		texture[4];
	t_mlx		*mlx;
}			t_zone;

struct s_draw
{
	double	pos_x;
	double	pos_y;
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
	double	rot;
	t_zone	*zone;
};

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
void	draw_background(t_zone *zone);
int		deal_key(int key, t_zone *zone);
int		color_get(t_img img, int x, int y);
int		color_shift_int(int base, int shift, double force);
t_rgb	color_shift_rgb(t_rgb base, t_rgb shift, double force);
t_rgb	color_int_to_rgb(int color);
void	draw_other(t_draw *draw, t_zone *zone);
void	press_ws(int key, t_zone *zone);
int		key_press(int key, t_zone *zone);
int		key_release(int key, t_zone *zone);
int		pos_map(t_zone *zone, int x, int y, int *player_found);
void	rotate(int key, t_zone *zone);

#endif
