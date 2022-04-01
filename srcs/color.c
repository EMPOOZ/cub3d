/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmicheli <rmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:02:54 by rmicheli          #+#    #+#             */
/*   Updated: 2022/03/30 14:09:43 by rmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_color(t_rgb rgb)
{
	int	color_int;

	color_int = rgb.r << 16 | rgb.g << 8 | rgb.b;
	return (color_int);
}

t_rgb	color_int_to_rgb(int color)
{
	t_rgb	rgb;

	rgb.r = (color >> 16) & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
	rgb.b = color & 0xFF;
	return (rgb);
}

int	color_shift_int(int base, int shift, double force)
{
	t_rgb	rgb;
	t_rgb	base_rgb;
	t_rgb	shift_rgb;

	if (base == 0x980088)
		return (base);
	base_rgb = color_int_to_rgb(base);
	shift_rgb = color_int_to_rgb(shift);
	rgb = color_shift_rgb(base_rgb, shift_rgb, force);
	return (init_color(rgb));
}

t_rgb	color_shift_rgb(t_rgb base, t_rgb shift, double force)
{
	force = 0;
	shift.b = shift.b;
	return (base);
}
