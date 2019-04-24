/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:33:59 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/24 19:10:16 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

void		put_pixel(t_env env, int x, int y, int color)
{
	int		pos;

	pos =  y * WIDTH + x;
	env.str_img[pos] = color;
}

void		draw_line(t_env *env, int color)
{
	int		x_slope;
	int		y_slope;
	int		dir_x;
	int		dir_y;
	int		error;
	int		temp;

	x_slope = env->x1 - env->x2 < 0 ? (env->x2 - env->x1) : (env->x1 - env->x2);
	y_slope = env->y1 - env->y2 < 0 ? (env->y2 - env->y1) : (env->y1 - env->y2);
	dir_x = env->x1 < env->x2 ? 1 : -1;
	dir_y = env->y1 < env->y2 ? 1 : -1;
	error = (x_slope > y_slope ? x_slope : y_slope * -1) / 2;
	while (env->x1 != env->x2 || env->y1 != env->y2)
	{
		put_pixel(*env, env->x1, env->y1, color);
		temp = error;
		if (temp > (x_slope * -1))
		{
			error -= dir_y;
			env->x1 += dir_x;
		}
		if (temp < y_slope)
		{
			error += dir_x;
			env->y1 += dir_y;
		}
	}
}

void		assign_points_toconnect(t_env *env, int p1, int p2)
{
	env->x1 = env->projected[p1][0];
	env->x2 = env->projected[p2][0];
	env->y1 = env->projected[p1][1];
	env->y2 = env->projected[p2][1];
}

void		display_img(t_env env)
{
	int				i;
	int				size;

	env.img = mlx_new_image(env.mlx_ptr, WIDTH, HEIGHT);
	env.str_img = (int *)mlx_get_data_addr(env.img, &(env.bpp), &(env.s_l), &(env.endian));
	put_pixel(env, 100, 100, 0xFFFFF);
	assign_points_toconnect(&env, 0, 1);
	draw_line(&env, 0xFFFFF);
/*	i = -1;
	size = env->x * env->y;
	while (++i < size - 1)
	{
		if ((i + 1) % env->x != 0)
			draw_line(str_img, env->projected[i], env->projected[i + 1], size_line);
		if ((i + env->x) < size)
			draw_line(str_img, env->projected[i], env->projected[i + env->x], size_line);
	}
*/
	mlx_put_image_to_window(env.mlx_ptr, env.window, env.img, 0, 0);
}
