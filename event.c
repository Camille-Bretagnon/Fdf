/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:47:14 by cbretagn          #+#    #+#             */
/*   Updated: 2019/05/03 19:55:24 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>

void		increase_z_value(t_env *env, int size, int add)
{
	int		i;

	i = -1;
	if ((add < 0 && env->ground_z < 0) || (add > 0 && env->ground_z > 0))
		return ;
	env->ground_z = 0;
	while (++i < size)
	{
		if (((int)env->points > 0 && (int)env->points[i][2] + add == 0)
			|| ((int)env->points < 0 && (int)env->points[i][2] - add == 0))
			env->ground_z = add < 0 ? -1 : 1;
		if ((int)env->points[i][2] != 0)
		{
			if ((int)env->points < 0 && (int)env->points[i][2] - add != 0)
				env->points[i][2] -= add;
			if ((int)env->points[i][2] > 0 && (int)env->points[i][2] + add != 0)
				env->points[i][2] += add;
		}
	}
	mlx_destroy_image(env->mlx_ptr, env->img);
	display_img(env);
}

void		x_matrix_rotation(t_env *env, float add)
{
	env->matrix->x_angle += add;
	x_matrix(env->matrix, env->matrix->x_angle);
	mlx_destroy_image(env->mlx_ptr, env->img);
	display_img(env);
}

void		y_matrix_rotation(t_env *env, float add)
{
	env->matrix->y_angle += add;
	y_matrix(env->matrix, env->matrix->y_angle);
	mlx_destroy_image(env->mlx_ptr, env->img);
	display_img(env);
}

void		projection_change(t_env *env)
{
	env->projection = env->projection == 5 ? 0 : env->projection + 1;
	if (env->projection == 0)
		change_xymatrix(env, 0.523599, 0.523599);
	if (env->projection == 1)
		change_xymatrix(env, 0, 1.5708);
	if (env->projection == 2)
		change_xymatrix(env, 1.5708, 0);
	if (env->projection == 3)
		change_xymatrix(env, 0.523599, 1.0472);
	if (env->projection == 4)
		change_xymatrix(env, 1.0472, 0.523599);
	if (env->projection == 5)
		change_xymatrix(env, 0, 0);
	mlx_destroy_image(env->mlx_ptr, env->img);
	display_img(env);
}

int			key_handle(int keycode, t_env *env)
{
	if (keycode == 8)
		change_color(env);
	if (keycode == 35)
		projection_change(env);
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		key_move(keycode, env);
	if (keycode == 125)
		x_matrix_rotation(env, 0.03);
	if (keycode == 126)
		x_matrix_rotation(env, -0.03);
	if (keycode == 123)
		y_matrix_rotation(env, 0.03);
	if (keycode == 124)
		y_matrix_rotation(env, -0.03);
	if (keycode == 12)
		increase_z_value(env, env->x * env->y, 1);
	if (keycode == 14)
		increase_z_value(env, env->x * env->y, -1);
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx_ptr, env->window);
		exit(0);
	}
	return (1);
}
