/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 10:13:27 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/26 12:22:07 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

int		exit_key(int keycode, t_env *env)
{
	if (keycode == 12)
	{
		mlx_destroy_window(env->mlx_ptr, env->window);
		exit(0);
	}
	return 1;
}

int		main(int argc, char **argv)
{
	t_env		*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	if (!(env->line = (t_param_line *)malloc(sizeof(t_param_line))))
		return (-1);
	if (!(env->matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		return (-1);
	matrix_init(env->matrix);
	x_matrix(env->matrix, 0.523599);
	y_matrix(env->matrix, 0.5);
	//z_matrix(env->matrix, 90);
	print_matrix(env->matrix->mat);
	print_matrix(env->matrix->x);
	print_matrix(env->matrix->y);
	print_matrix(env->matrix->z);
	env->mlx_ptr = mlx_init();
	env->window = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "test");
	env->points = get_points(argv[1], env);
	print_array_points(env->points, env->x, env->y);
	//env.projected = generate_array(env.x, env.y);
	//parallel_proj(env.projected, env.points, env.x, env.y);
	//print_projected(env.projected, env.x, env.y);
	display_img(env);
	mlx_hook(env->window, 2, 4, key_handle, env);
	mlx_loop(env->mlx_ptr);
}
