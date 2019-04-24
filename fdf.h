/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:02:41 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/24 11:49:52 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define WIDTH 1600
#define HEIGHT 1200
#define BASE 20.0
#define	COLOR 0xFFFFFF

typedef struct s_env
{
			void	*mlx_ptr;
			void	*window;
			float	**array_points;
			int		*projected_points;
}				t_env;

#endif
