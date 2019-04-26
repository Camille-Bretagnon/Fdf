/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 11:47:14 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/26 12:22:05 by cbretagn         ###   ########.fr       */
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
		if ((int)env->points[i][2] != 0 && (int)(env->points[i][2] + add) != 0)
			env->points[i][2] += add;
	}
	mlx_destroy_image(env->mlx_ptr, env->img);
	display_img(env);
}

int			key_handle(int keycode, t_env *env)
{
	if (keycode == 126)
		increase_z_value(env, env->x * env->y, 10);
	if (keycode == 125)
		increase_z_value(env, env->x * env->y, -10);
	if (keycode == 12)
	{
		mlx_destroy_window(env->mlx_ptr, env->window);
		exit(0);
	}
	return (1);
}
