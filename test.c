/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:22:40 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/04 18:13:15 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void		hour0(void *display, void *window, int x1, int y1, int x2, int y2)
{
	int		color;

	color = 0xFFFFFF;
	while (y1 > y2)
	{
		mlx_pixel_put(display, window, x1, y1, color);
		y1--;
	}
}

void		hour1(void *display, void *window, int x1, int y1, int x2, int y2)
{
	int		error;
	int		x_slope;
	int		y_slope;
	int		color;

	color = 0xFFFFFF;
	error = y1 - y2;
	x_slope = (x2 - x1) * 2;
	y_slope = error * 2;
	while (y1 > y2)
	{
		mlx_pixel_put(display, window, x1, y1, color);
		y1--;
		error = error - x_slope;
		if (error <= 0)
		{
			x1++;
			error = error + y_slope;
		}
	}
}

void		hour2(void *display, void *window, int x1, int y1, int x2, int y2)
{
	int		error;
	int		x_slope;
	int		y_slope;
	int		color;

	color = 0xFFFFFF;
	error = x2 - x1;
	x_slope = error * 2;
	y_slope = (y1 - y2) * 2;
	while (x1 < x2)
	{
		mlx_pixel_put(display, window, x1, y1, color);
		x1++;
		error = error - y_slope;
		if (error <= 0)
		{
			y1--;
			error = error + x_slope;
		}
	}
}

void		hour3(void *display, void *window, int x1, int y1, int x2, int y2)
{
	int		color;

	color = 0xFFFFFF;
	while (x1 < x2)
	{
		mlx_pixel_put(display, window, x1, y1, color);
		x1++;
	}
}

void		hour4(void *display, void *window, int x1, int y1, int x2, int y2)
{
	int		error;
	int		x_slope;
	int		y_slope;
	int		color;

	color = 0xFFFFFF;
	error = x2 - x1;
	x_slope = error * 2;
	y_slope = (y2 - y1) * 2;
	while (x1 < x2)
	{
		mlx_pixel_put(display, window, x1, y1, color);
		x1++;
		error = error - y_slope;
		if (error <= 0)
		{
			y1++;
			error = error + x_slope;
		}
	}
}

void		hour5(void *display, void *window, int x1, int y1, int x2, int y2)
{
	int		error;
	int		x_slope;
	int		y_slope;
	int		color;

	color = 0xFFFFFF;
	error = y2 - y1;
	x_slope = (x2 - x1) * 2;
	y_slope = (y2 - y1) * 2;
	while (y1 < y2)
	{
		mlx_pixel_put(display, window, x1, y1, color);
		y1++;
		error = error - x_slope;
		if (error <= 0)
		{
			x1++;
			error = error + y_slope;
		}
	}
}

void		hour6(void *display, void *window, int x1, int y1, int x2, int y2)
{
	int		color;

	color = 0xFFFFFF;
	while (y1 < y2)
	{
		mlx_pixel_put(display, window, x1, y1, color);
		y1++;
	}
}

int			abs(int nb)
{
	return (nb < 0 ? nb * -1 : nb);
}

void		draw_line(void *display, void *window, int x1, int y1, int x2, int y2)
{
	int			i;
	int			x_slope;
	int			y_slope;
	int			temp;
	static void	(*array_draw_line[7])(void	*display, void	*window, 
			int x1, int y1, int x2, int y2) 
		= {hour0, hour1, hour2, hour3, hour4, hour5, hour6};

	if (x2 < x1)
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	x_slope = x2 - x1;
	y_slope = y2 - y1;
	if (x_slope == 0)
		i = (y_slope < 0) ? 0 : 6;
	else if (y_slope == 0)
		i = 3;
	else if (abs(x_slope) < abs(y_slope))
		i = (y_slope < 0) ? 1 : 5;
	else
		i = (y_slope < 0) ? 2 : 4;
	array_draw_line[i](display, window, x1, y1, x2, y2);
}

void		draw_line_test(void *display, void *window, int x1, int y1, int x2, int y2)
{
	int		error;
	int		x_slope;
	int		y_slope;
	int		color;

	color = 0xFFFFFF;
	error = x2 - x1;
	x_slope = error * 2;
	y_slope = (y1 - y2) * 2;
	while (x1 < x2)
	{
		mlx_pixel_put(display, window, x1, y1, color);
		x1++;
		error = error - y_slope;
		if (error <= 0)
		{
			y1--;
			error = error + x_slope;
		}
	}
}

int		main()
{
	void	*display;
	void	*window;

	display = mlx_init();
	window = mlx_new_window(display, 500, 500, "un affichage random");
	draw_line(display, window, 450, 250, 50, 250);
	mlx_loop(display);
	return (0);
}
