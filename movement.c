/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:11:47 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/25 15:33:18 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include <mlx.h>

void		copy_matrix(float src[9], float dst[9])
{
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	dst[3] = src[3];
	dst[4] = src[4];
	dst[5] = src[5];
	dst[6] = src[6];
	dst[7] = src[7];
	dst[8] = src[8];
}

void		compute_matrix(t_matrix *matrix, float rotation[9])
{
	float		temp[9];

	copy_matrix(matrix->mat, temp);
	matrix->mat[0] = temp[0] * 
	matrix->mat[1] =
	matrix->mat[2] =
	matrix->mat[3] =
	matrix->mat[4] =
	matrix->mat[5] =
	matrix->mat[6] =
	matrix->mat[7] =
	matrix->mat[8] =
