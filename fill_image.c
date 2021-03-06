/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:33:59 by cbretagn          #+#    #+#             */
/*   Updated: 2019/05/03 18:06:13 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

void		put_pixel(t_env env, int x, int y, int color)
{
	int		pos;

	if (x < 0 || x > IMG_W || y < 0 || y > IMG_H)
		return ;
	pos = y * IMG_W + x;
	env.str_img[pos] = color;
}

void		draw_line(t_env *env, int color)
{
	int		error;
	int		temp;

	error = (env->line->x_slope > env->line->y_slope ?
			env->line->x_slope : -(env->line->y_slope)) / 2;
	while (env->line->x1 != env->line->x2 || env->line->y1 != env->line->y2)
	{
		put_pixel(*env, env->line->x1, env->line->y1, color);
		temp = error;
		if (temp > -(env->line->x_slope))
		{
			error -= env->line->y_slope;
			env->line->x1 += env->line->dir_x;
		}
		if (temp < env->line->y_slope)
		{
			error += env->line->x_slope;
			env->line->y1 += env->line->dir_y;
		}
	}
}

void		assign_points(t_env *env, int p1, int p2)
{
	compute_points(env, env->matrix, p1, p2);
	env->line->x1 = plot(env->line->x1 + env->x_modifier);
	env->line->y1 = plot(env->line->y1 + env->y_modifier);
	env->line->x2 = plot(env->line->x2 + env->x_modifier);
	env->line->y2 = plot(env->line->y2 + env->y_modifier);
	env->line->x_slope = abs(env->line->x2 - env->line->x1);
	env->line->y_slope = abs(env->line->y2 - env->line->y1);
	env->line->dir_x = env->line->x1 < env->line->x2 ? 1 : -1;
	env->line->dir_y = env->line->y1 < env->line->y2 ? 1 : -1;
}

void		display_img(t_env *env)
{
	int				i;
	int				size;

	env->img = mlx_new_image(env->mlx_ptr, IMG_W, IMG_H);
	env->str_img = (int *)mlx_get_data_addr(env->img,
			&env->bpp, &env->s_l, &env->endian);
	i = -1;
	size = env->x * env->y;
	while (++i < size - 1)
	{
		if ((i + 1) % env->x != 0)
		{
			assign_points(env, i, i + 1);
			draw_line(env, env->color);
		}
		if ((i + env->x) < size)
		{
			assign_points(env, i, i + env->x);
			draw_line(env, env->color);
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->window, env->img,
			WIDTH - IMG_W, HEIGHT - IMG_H);
}
