/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:39:17 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/25 12:58:47 by cbretagn         ###   ########.fr       */
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
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			if (i == j)
				matrix->mat[i][j] = 1;
			else
				matrix->mat[i][j] = 0;
		}
	}
}

void		x_matrix(t_matrix *matrix, float angle)
{
	matrix->x[0][0] = 1;
	matrix->x[0][1] = 0;
	matrix->x[0][2] = 0;
	matrix->x[1][0] = 0;
	matrix->x[1][1] = cos(angle);
	matrix->x[1][2] = -(sin(angle));
	matrix->x[2][0] = 0;
	matrix->x[2][1] = sin(angle);
	matrix->x[2][2] = cos(angle);
}

void		y_matrix(t_matrix *matrix, float angle)
{
	matrix->y[0][0] = cos(angle);
	matrix->y[0][1] = 0;
	matrix->y[0][2] = sin(angle);
	matrix->y[1][0] = 0;
	matrix->y[1][1] = 1;
	matrix->y[1][2] = 0;
	matrix->y[2][0] = -(sin(angle));
	matrix->y[2][1] = 0;
	matrix->y[2][2] = cos(angle);
}
void		z_matrix(t_matrix *matrix, float angle)
{
	matrix->z[0][0] = cos(angle);
	matrix->z[0][1] = -(sin(angle));
	matrix->z[0][2] = 0;
	matrix->z[1][0] = sin(angle);
	matrix->z[1][1] = cos(angle);
	matrix->z[1][2] = 0;
	matrix->z[2][0] = 0;
	matrix->z[2][1] = 0;
	matrix->z[2][2] = 1;
}

//TODO remove

void		print_matrix(t_matrix *matrix)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			printf("% 5.0f", matrix->mat[i][j]);
		printf("% 10s", "");
		j = -1;
		while (++j < 3)
			printf("% 5.0f", matrix->x[i][j]);
		printf("% 10s", "");
		j = -1;
		while (++j < 3)
			printf("% 5.0f", matrix->y[i][j]);
		printf("% 10s", "");
		j = -1;
		while (++j < 3)
			printf("% 5.0f", matrix->z[i][j]);
		printf("% 10s", "");
		printf("\n");
	}
}
void		compute_matrix(t_matrix *matrix)
{
