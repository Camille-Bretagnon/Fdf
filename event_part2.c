/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:11:58 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/26 13:59:20 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void		zoom(t_env *env, float add)
{
	if (env->zoom + add > 0 && env->zoom + add < 10)
		env->zoom += add;
	mlx_destroy_image(env->mlx_ptr, env->img);
	display_img(env);
}

void		move_lr(t_env *env, int add)
{
	if (env->x_modifier + add > -IMG_W
			&& env->x_modifier + add < IMG_W)
		env->x_modifier += add;
	mlx_destroy_image(env->mlx_ptr, env->img);
	display_img(env);
}

void		move_ud(t_env *env, int add)
{
	if (env->y_modifier + add > -IMG_H 
			&& env->y_modifier + add < IMG_H)
		env->y_modifier += add;
	mlx_destroy_image(env->mlx_ptr, env->img);
	display_img(env);
}
