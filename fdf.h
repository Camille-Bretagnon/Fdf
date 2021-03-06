/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:02:41 by cbretagn          #+#    #+#             */
/*   Updated: 2019/05/03 19:53:26 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIDTH 	1600
# define HEIGHT 1200
# define IMG_W 	1200
# define IMG_H 	1200

# define BLUE 	0x5439ee
# define RED	0xba003a
# define GREEN 	0x75d726
# define WHITE 	0xFFFFFF

typedef struct		s_param_line
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				x_slope;
	int				y_slope;
	int				dir_x;
	int				dir_y;
}					t_param_line;

typedef struct		s_matrix
{
	float			x_angle;
	float			y_angle;
	float			x[9];
	float			y[9];
}					t_matrix;

typedef struct		s_env
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
	int				color;
	int				ground_z;
	int				projection;
	int				x_modifier;
	int				y_modifier;
	float			**points;
	t_param_line	*line;
	t_matrix		*matrix;
}					t_env;

void				put_pixel(t_env env, int x, int y, int color);
void				draw_line(t_env *env, int color);
void				display_img(t_env *env);
void				assign_points(t_env *env, int p1, int p2);

int					plot(float nb);
float				**generate_array_points(int x, int y);
float				**get_points(char *file, t_env *env);

void				matrix_init(t_matrix *matrix);
void				x_matrix(t_matrix *matrix, float angle);
void				y_matrix(t_matrix *matrix, float angle);
void				z_matrix(t_matrix *matrix, float angle);
void				compute_points(t_env *env,
							t_matrix *matrix, int p1, int p2);

int					key_handle(int keycode, t_env *env);
void				move_ud(t_env *env, int add);
void				move_lr(t_env *env, int add);
void				key_move(int keycode, t_env *env);
void				change_color(t_env *env);
void				change_xymatrix(t_env *env, float x_angle, float y_angle);

void				clipping(t_env *env);
void				malloc_error(void);
int					close_fd(int fd, int lines);
#endif
