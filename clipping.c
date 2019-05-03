/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:40:31 by cbretagn          #+#    #+#             */
/*   Updated: 2019/05/03 19:54:29 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void		adjust_xy(t_env *env, int size)
{
	int		adjust_x;
	int		adjust_y;
	int		i;

	adjust_x = (int)(env->points[size - 1][0] / 2);
	adjust_y = (int)(env->points[0][1] / 2);
	env->x_modifier = IMG_W / 2;
	env->y_modifier = -(IMG_H / 2);
	i = -1;
	while (++i < size)
	{
		env->points[i][0] -= adjust_x;
		env->points[i][1] -= adjust_y;
	}
}

void		clipping(t_env *env)
{
	adjust_xy(env, env->x * env->y);
}
