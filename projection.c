/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:54:16 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/24 19:11:08 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		plot(float nb)
{
	return ((int)(nb + 0.5));
}

int		**generate_array(int x, int y)
{
	int		**ret;
	int		i;

	i = -1;
	if (!(ret = (int **)malloc(sizeof(int *) * (x * y))))
		return (NULL);
	while (++i < x * y)
	{
		if (!(ret[i] = (int *)malloc(sizeof(int) * 2)))
			return (NULL);
	}
	return (ret);
}

void	parallel_proj(int	**projected, float **points, int x, int y)
{
	int		size;
	int		i;

	size = x * y;
	i = -1;
	while (++i < size)
	{
		projected[i][0] = plot(points[i][0]);
		projected[i][1] = plot(points[i][1]);
	}
}

//TODO remove

#include <stdio.h>

void		print_projected(int	**projected, int x, int y)
{
	int		i;

	i = -1;
	while (++i < x * y)
	{
		if (i % x == 0)
			printf("\n");
		printf("%d, %d; ", projected[i][0], projected[i][1]);
	}
}
