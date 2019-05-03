/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 10:13:27 by cbretagn          #+#    #+#             */
/*   Updated: 2019/05/03 17:41:31 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

void		initialize(t_env *env)
{
	matrix_init(env->matrix);
	env->matrix->x_angle = 0.523599;
	env->matrix->y_angle = 0.523599;
	x_matrix(env->matrix, env->matrix->x_angle);
	y_matrix(env->matrix, env->matrix->y_angle);
	env->color = 0xFFFFFF;
	env->ground_z = 0;
	env->mlx_ptr = mlx_init();
	env->window = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Fdf_");
}

void		malloc_error(void)
{
	write(1, "malloc error\n", 13);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_env		*env;

	if (argc != 2)
	{
		write(1, "usage : ./fdf [file_map]", 24);
		exit(0);
	}
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		malloc_error();
	if (!(env->line = (t_param_line *)malloc(sizeof(t_param_line))))
		malloc_error();
	if (!(env->matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		malloc_error();
	initialize(env);
	if (!(env->points = get_points(argv[1], env)))
	{
		write(1, "Invalid map\n", 12);
		exit(0);
	}
	clipping(env);
	print_array_points(env->points, env->x, env->y);
	display_img(env);
	mlx_hook(env->window, 2, 4, key_handle, env);
	mlx_loop(env->mlx_ptr);
}
