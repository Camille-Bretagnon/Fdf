/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 10:13:27 by cbretagn          #+#    #+#             */
/*   Updated: 2019/05/03 19:59:37 by cbretagn         ###   ########.fr       */
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
	env->projection = 0;
	env->mlx_ptr = mlx_init();
	env->window = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Fdf_");
}

void		malloc_error(void)
{
	write(1, "malloc error\n", 13);
	exit(0);
}

void		display_commands(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->window, 60, 60,
			GREEN, "MOVE LEFT_RIGHT      A -- D");
	mlx_string_put(env->mlx_ptr, env->window, 60, 120,
			GREEN, "MOVE UP_DOWN         W -- S");
	mlx_string_put(env->mlx_ptr, env->window, 60, 180,
			GREEN, "Y ROTATION           ARROW KEYS LR");
	mlx_string_put(env->mlx_ptr, env->window, 60, 240,
			GREEN, "X ROTATION");
	mlx_string_put(env->mlx_ptr, env->window, 270, 240,
			GREEN, "ARROW KEYS UD");
	mlx_string_put(env->mlx_ptr, env->window, 60, 300,
			GREEN, "CHANGE COLOR         C");
	mlx_string_put(env->mlx_ptr, env->window, 60, 360,
			GREEN, "CHANGE PROJECTION    P");
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
	display_commands(env);
	clipping(env);
	display_img(env);
	mlx_hook(env->window, 2, 4, key_handle, env);
	mlx_loop(env->mlx_ptr);
}
