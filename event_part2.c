/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:11:58 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/30 14:07:15 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

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

void		change_color(t_env *env)
{
	if (env->color == WHITE)
		env->color = BLUE;
	else if (env->color == BLUE)
		env->color = GREEN;
	else if (env->color == GREEN)
		env->color = RED;
	else
		env->color = WHITE;
	mlx_destroy_image(env->mlx_ptr, env->img);
	display_img(env);
}

void		key_move(int keycode, t_env *env)
{
	if (keycode == 13)
		move_ud(env, -10);
	if (keycode == 1)
		move_ud(env, 10);
	if (keycode == 0)
		move_lr(env, -10);
	if (keycode == 2)
		move_lr(env, 10);
}
