/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:47:14 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/26 16:14:08 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdlib.h>

void		increase_z_value(t_env *env, int size, int add)
{
	int		i;

	i = -1;
	while (++i < size)
	{
		if ((int)env->points[i][2] > env->ground_z)
			env->points[i][2] += add;
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

int			key_handle(int keycode, t_env *env)
{
	if (keycode == 69)
		zoom(env, 0.1);
	if (keycode == 76)
		zoom(env, -0.1);
	if (keycode == 13)
		move_ud(env, -10);
	if (keycode == 1)
		move_ud(env, 10);
	if (keycode == 0)
		move_lr(env, -10);
	if (keycode == 2)
		move_lr(env, 10);
	if (keycode == 125)
		x_matrix_rotation(env, 0.03);
	if (keycode == 126)
		x_matrix_rotation(env, -0.03);
	if (keycode == 123)
		y_matrix_rotation(env, 0.03);
	if (keycode == 124)
		y_matrix_rotation(env, -0.03);
	if (keycode == 12)
		increase_z_value(env, env->x * env->y, 10);
	if (keycode == 14)
		increase_z_value(env, env->x * env->y, -10);
	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx_ptr, env->window);
		exit(0);
	}
	return (1);
}
