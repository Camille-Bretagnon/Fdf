/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:33:07 by cbretagn          #+#    #+#             */
/*   Updated: 2019/05/03 19:59:54 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <stdlib.h>

int			plot(float nb)
{
	return ((int)(nb + 0.5));
}

int			close_fd(int fd, int lines)
{
	close(fd);
	return (lines);
}

float		**generate_array_points(int x, int y)
{
	float		**ret;
	int			size;
	int			i;
	int 		base;
	int			base_x;
	int			base_y;
	
	i = -1;
	size = x * y;
	base_x = (int)((IMG_W * 0.60) / x);
	base_y = (int)((IMG_H * 0.60) / y);
	base = base_x < base_y ? base_x : base_y;
	if (!(ret = (float **)malloc(sizeof(float *) * size)))
		return (NULL);
	while (++i < size)
	{
		if (!(ret[i] = (float *)malloc(sizeof(float) * 3)))
			return (NULL);
		ret[i][0] = (i % x) * base;
		ret[i][1] = (x - i / x) * base;
		ret[i][2] = 0.0;
	}
	return (ret);
}
