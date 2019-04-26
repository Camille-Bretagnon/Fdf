/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:33:59 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/26 16:32:34 by cbretagn         ###   ########.fr       */
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
	pos =  y * IMG_W + x;
	env.str_img[pos] = color;
}

void		draw_line(t_env *env, int color)
{
	int		error;
	int		temp;

	error = (env->line->x_slope > env->line->y_slope ? env->line->x_slope : -(env->line->y_slope)) / 2;
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
	//env->line->x1 = plot(((env->points[p1][0]) - (env->points[p1][1])) * cos(0.523599)) + 200;
	//env->line->x2 = plot(((env->points[p2][0]) - (env->points[p2][1])) * cos(0.523599)) + 200;
	//env->line->y1 = plot(-(env->points[p1][2]) + (env->points[p1][0] + env->points[p1][1]) * cos (0.523599));
	//env->line->y2 = plot(-(env->points[p2][2]) + (env->points[p2][0] + env->points[p2][1]) * cos (0.523599));
	compute_points(env, env->matrix, p1, p2);
	env->line->x1 = plot((env->line->x1 + env->x_modifier) * env->zoom);
	env->line->y1 = plot((env->line->y1 + env->y_modifier) * env->zoom);
	env->line->x2 = plot((env->line->x2 + env->x_modifier) * env->zoom);
	env->line->y2 = plot((env->line->y2 + env->y_modifier) * env->zoom);
	env->line->x_slope = abs(env->line->x2 - env->line->x1);
	env->line->y_slope = abs(env->line->y2 - env->line->y1);
	env->line->dir_x = env->line->x1 < env->line->x2 ? 1 : -1;
	env->line->dir_y = env->line->y1 < env->line->y2 ? 1 : -1;
}

void		check_line(t_param_line *line)
{
	printf("\nx1 %d y1 %d x2 %d y2 %d\nx_slope %d y_slope %d\ndir_x %d dir_y %d\n",
			line->x1, line->y1, line->x2, line->y2, line->x_slope, line->y_slope,
			line->dir_x, line->dir_y);
}//TODO remove

void		display_img(t_env *env)
{
	int				i;
	int				size;

	env->img = mlx_new_image(env->mlx_ptr, IMG_W, IMG_H);
	env->str_img = (int *)mlx_get_data_addr(env->img, &env->bpp, &env->s_l, &env->endian);
	/*env->line->x1 = 0;
	env->line->y1 = 0;
	env->line->x2 = 16;
	env->line->y2 = -8;
	assign_points(env, 0, 1);
	draw_line(env, 0xFFFFF);
	*/i = -1;
	size = env->x * env->y;
	while (++i < size - 1)
	{
		if ((i + 1) % env->x != 0)
		{
			assign_points(env, i, i + 1);
			draw_line(env, 0xFFFFF);
		}
		if ((i + env->x) < size)
		{
			assign_points(env, i, i + env->x);
			draw_line(env, 0xFFFFF);
		}
	}
	mlx_put_image_to_window(env->mlx_ptr, env->window, env->img, WIDTH - IMG_W, HEIGHT - IMG_H);
}
