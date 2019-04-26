/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:39:17 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/26 12:46:04 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

void		matrix_init(t_matrix *matrix)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 9)
	{
		if (i % 4 == 0)
			j = 1;
		else
			j = 0;
		matrix->x[i] = j;
		matrix->y[i] = j;
	}
}

void		x_matrix(t_matrix *matrix, float angle)
{
	matrix->x[0] = 1;
	matrix->x[1] = 0;
	matrix->x[2] = 0;
	matrix->x[3] = 0;
	matrix->x[4] = cos(angle);
	matrix->x[5] = -(sin(angle));
	matrix->x[6] = 0;
	matrix->x[7] = sin(angle);
	matrix->x[8] = cos(angle);
}

void		y_matrix(t_matrix *matrix, float angle)
{
	matrix->y[0] = cos(angle);
	matrix->y[1] = 0;
	matrix->y[2] = sin(angle);
	matrix->y[3] = 0;
	matrix->y[4] = 1;
	matrix->y[5] = 0;
	matrix->y[6] = -(sin(angle));
	matrix->y[7] = 0;
	matrix->y[8] = cos(angle);
}

//TODO remove
void		print_matrix(float matrix[9])
{
	printf("\n% 5.0f% 5.0f% 5.0f", matrix[0], matrix[1], matrix[2]);
	printf("\n% 5.0f% 5.0f% 5.0f", matrix[3], matrix[4], matrix[5]);
	printf("\n% 5.0f% 5.0f% 5.0f\n", matrix[6], matrix[7], matrix[8]);
}
//TODO remove

void		compute_points(t_env *env, t_matrix *matrix, int p1, int p2)
{
	float	new_x;
	float	new_y;
	float	new_z;

	new_x = env->points[p1][0] * matrix->x[0] + env->points[p1][1] 
		* matrix->x[3] + env->points[p1][2] * matrix->x[6];
	new_y = env->points[p1][0] * matrix->x[1] + env->points[p1][1]
		* matrix->x[4] + env->points[p1][2] * matrix->x[7];
	new_z = env->points[p1][0] * matrix->x[2] + env->points[p1][1]
		* matrix->x[5] + env->points[p1][2] * matrix->x[8];
	new_x = new_x * matrix->y[0] + new_y * matrix->y[3] + new_z * matrix->y[6];
	new_y = new_x * matrix->y[1] + new_y * matrix->y[4] + new_z * matrix->y[7];
	env->line->x1 = plot(new_x);
	env->line->y1 = IMG_H - plot(new_y);
	new_x = env->points[p2][0] * matrix->x[0] + env->points[p2][1]
		* matrix->x[3] + env->points[p2][2] * matrix->x[6];
	new_y = env->points[p2][0] * matrix->x[1] + env->points[p2][1]
		* matrix->x[4] + env->points[p2][2] * matrix->x[7];
	new_z = env->points[p2][0] * matrix->x[2] + env->points[p2][1]
		* matrix->x[5] + env->points[p2][2] * matrix->x[8];
	new_x = new_x * matrix->y[0] + new_y * matrix->y[3] + new_z * matrix->y[6];
	new_y = new_x * matrix->y[1] + new_y * matrix->y[4] + new_z * matrix->y[7];
	env->line->x2 = plot(new_x);
	env->line->y2 = IMG_H - plot(new_y);
}
