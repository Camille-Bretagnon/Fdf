/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 10:13:27 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/24 18:23:46 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

int		exit_key(int keycode, t_env env)
{
	if (keycode == 12)
	{
		mlx_destroy_window(env.mlx_ptr, env.window);
		exit(0);
	}
	return 1;
}

int		main(int argc, char **argv)
{
	t_env		env;

	//env = malloc(sizeof(t_env));
	env.mlx_ptr = mlx_init();
	env.window = mlx_new_window(env.mlx_ptr, WIDTH, HEIGHT, "test");
	env.points = get_points(argv[1], &env);
	env.projected = generate_array(env.x, env.y);
	parallel_proj(env.projected, env.points, env.x, env.y);
	display_img(env);
	mlx_key_hook(env.window, exit_key, &env);
	mlx_loop(env.mlx_ptr);
}
