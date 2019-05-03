/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:40:31 by cbretagn          #+#    #+#             */
/*   Updated: 2019/05/03 15:51:35 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void		min_z(t_env *env, int size)
{
	int i;
	int	ret;

	i = 0;
	ret = env->points[0][2];
	while (++i < size)
	{
		if (env->points[i][2] < ret)
			ret = env->points[i][2];
	}
	env->ground_z = ret;
	printf("\ni is %d ground %d\n", i, env->ground_z);
}

int			max_z(float **array, int size)
{
	int		i;
	int		ret;

	i = 0;
	ret = (int)array[0][2];
	while (++i < size)
	{
		if ((int)array[i][2] > ret)
			ret = (int)array[i][2];
	}
	return (ret);
}

//TODO remove
void		adjust_z(t_env *env, int size)
{
	int		i;
	int		adjust;

	i = -1;
	min_z(env, env->x * env->y);
	adjust = (max_z(env->points, size) - env->ground_z);
	if (adjust == 0)
		return ;
	adjust /= 2;
	printf("adjust is %d\n", adjust);
	while (++i < size)
		env->points[i][2] -= adjust;
	min_z(env, env->x * env->y);
}

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
	//min_z(env, env->x * env->y);
	//adjust_z(env, env->x * env->y);
}
