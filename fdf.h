/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:02:41 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/24 18:23:43 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define WIDTH 1600
#define HEIGHT 1200
#define IMG_WIDTH 1200
#define IMG_HEIGHT 800
#define BASE 20.0
#define	COLOR 0xFFFFFF

typedef struct s_env
{
			void			*mlx_ptr;
			void			*window;
			void			*img;
			int				*str_img;
			int				x;
			int				y;
			int				bpp;
			int				s_l;
			int				endian;
			float			**points;
			int				**projected;
			int				current_x1;
			int				current_y1;
			int				current_x2;
			int				current_y2;
}				t_env;

void		put_pixel(t_env env, int x, int y, int color);
void		draw_line(t_env env, int color);
void		display_img(t_env env);

int			plot(float nb);
int			**generate_array(int x, int y);
void		parallel_proj(int **projected, float **points, int x, int y);

float		**generate_array_points(int x, int y);

float		**get_points(char *file, t_env *env);
//TODO remove
void		print_point(float *point, int i, int x);
void		print_array_points(float **array, int x, int y);

#endif
