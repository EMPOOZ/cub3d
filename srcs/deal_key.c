// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   deal_key.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: tconwy <tconwy@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/03/29 17:19:45 by rmicheli          #+#    #+#             */
// <<<<<<< HEAD
// /*   Updated: 2022/04/03 14:54:42 by rmicheli         ###   ########.fr       */
// =======
// /*   Updated: 2022/04/01 13:52:23 by tconwy           ###   ########.fr       */
// >>>>>>> tconwy
// /*                                                                            */
// /* ************************************************************************** */

// #include "../cub3d.h"
// <<<<<<< HEAD
// /*
// int	mouse_handler(int x, int y)
// =======

// void	press_s(t_zone *zone, t_draw *draw)
// {
// 	if (zone->matr_int[(int)(draw->pos_x - draw->dir_x * 0.25)][(int)draw->pos_x]
// 		== 0)
// 		draw->pos_x -= draw->dir_x * 0.25;
// 	if (zone->matr_int[(int)draw->pos_x][(int)(draw->pos_y - draw->dir_y * 0.25)]
// 		== 0)
// 		draw->pos_y -= draw->dir_y * 0.25;
// }

// void	press_w(t_zone *zone, t_draw *draw)
// {
// 	if (zone->matr_int[(int)(draw->pos_x + draw->dir_x * 0.25)][(int)draw->pos_x]
// 		== 0)
// 		draw->pos_x += draw->dir_x * 0.25;
// 	if (zone->matr_int[(int)draw->pos_x][(int)(draw->pos_y + draw->dir_y * 0.25)]
// 		== 0)
// 		draw->pos_y += draw->dir_y * 0.25;
// }

// void	press_a(t_draw *draw)
// >>>>>>> tconwy
// {
// 	static int	mouse_x = 0;
// 	static int	mouse_y = 0;

// <<<<<<< HEAD
// 	if (mouse_x != x)
// 		rotate_player(&g_game.player, (mouse_x - x) * MOUSE_TURN);
// 	mouse_x = x;
// 	mouse_y = y;
// 	return (0);
// =======
// 	old_dir_x = draw->dir_x;
// 	old_plane_x = draw->plane_x;
// 	draw->dir_x = draw->dir_x * cos(0.5) - draw->dir_y * sin(0.5);
// 	draw->dir_y = old_dir_x * sin(0.5) + draw->dir_y * cos(0.5);
// 	draw->plane_x = draw->plane_x * cos(0.5) - draw->plane_y * sin(0.5);
// 	draw->plane_y = old_plane_x * sin(0.5) + draw->plane_y * cos(0.5);
// 	printf("\nqwe\n");
// >>>>>>> tconwy
// }
// */
// int	key_press(int key, t_zone *zone)
// {
// 	double	modifier;

// <<<<<<< HEAD
// 	modifier = ((double)1000 * (double)1000) / 1000000.0;
// 	if (key == 123)
// 		zone->player->turn_l = 8 * modifier;
// 	if (key == 124)
// 		zone->player->turn_r = -8 * modifier;
// 	if (key == 13)
// 		zone->player->vel_u = 8 * modifier;
// 	if (key == 1)
// 		zone->player->vel_d = -8 * modifier;
// 	if (key == 0)
// 		zone->player->vel_l = 8 * modifier;
// 	if (key == 2)
// 		zone->player->vel_r = -8 * modifier;
// 	return (key);
// =======
// 	old_dir_x = draw->dir_x;
// 	old_plane_x = draw->plane_x;
// 	draw->dir_x = draw->dir_x * cos(-0.5) - draw->dir_y * sin(-0.5);
// 	draw->dir_y = old_dir_x * sin(-0.5) + draw->dir_y * cos(-0.5);
// 	draw->plane_x = draw->plane_x * cos(-0.5) - draw->plane_y * sin(-0.5);
// 	draw->plane_y = old_plane_x * sin(-0.5) + draw->plane_y * cos(-0.5);
// 	printf("\nqwe\n");
// >>>>>>> tconwy
// }

// int	key_release(int key, t_zone *zone)
// {
// <<<<<<< HEAD
// =======
// 	if (key == 1)
// 		press_s(zone, zone->draw);
// >>>>>>> tconwy
// 	if (key == 13)
// 		zone->player->vel_u = 0;
// 	if (key == 0)
// 		zone->player->vel_l = 0;
// 	if (key == 1)
// 		zone->player->vel_d = 0;
// 	if (key == 2)
// 		zone->player->vel_r = 0;
// 	if (key == 123)
// 		zone->player->turn_l = 0;
// 	if (key == 124)
// 		zone->player->turn_r = 0;
// 	if (key == 53)
// <<<<<<< HEAD
// 		exit(1);
// 	return (key);
// }

// int	quit_handler(void)
// {
// 	exit(1);
// =======
// 		exit(0);
// >>>>>>> tconwy
// 	return (0);
// }
