/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:10:51 by cbretagn          #+#    #+#             */
/*   Updated: 2019/04/26 11:47:08 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "./libft/libft.h"
#include "get_next_line.h"
#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int			nb_points(char	*str)
{
	int		ret;

	ret = 0;
	while (*str && *str != '\n')
	{
		while (*str == ' ')
			str++;
		if ((*str >= '0' && *str <= '9') || *str == '-')
			ret++;
		while ((*str >= '0' && *str <= '9') || *str == '-')
			str++;
		if (*str && *str != ' ' && *str != '\n')
			return (-1);
	}
	return (ret);
}

static int			nb_lines(char *file)
{
	int		fd;
	int		i;
	int		lines;
	char	buffer[4097];

	i = 0;
	lines = 0;
	buffer[4096] = '\0';
	fd = open(file, O_RDONLY);
	while (read(fd, buffer, 4096) > 0)
	{
		while (buffer[i] == '\n')
			i++;
		while (buffer[++i])
		{
			if (buffer[i] == '\n')
			{
				if (buffer[i - 1] == '\n')
				{
					close(fd);
					return (lines);
				}
				lines++;
			}
		}
	}
	close(fd);
	return (lines);
}

static char			*next_nbr(char *str, float *current)
{
	int		nb;
	int		sign;

	nb = 0;
	sign = 1;
	while (*str && *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	current[2] = nb * sign * 5;
	return (str);
}

float			**generate_array_points(int x, int y)
{
	float		**ret;
	int			size;
	int			i;

	i = -1;
	size = x * y;
	if (!(ret = (float **)malloc(sizeof(float *) * size)))
		return (NULL);
	while (++i < size)
	{
		if (!(ret[i] = (float *)malloc(sizeof(float) * 3)))
			return (NULL);
		ret[i][0] = (i % x) * BASE;
		ret[i][1] = (x - i / x) * BASE;
		ret[i][2] = 0.0;
	}
	return (ret);
}

//TODO remove

#include <stdio.h>

void			print_point(float *point, int i, int x)
{
	if (i % x == 0)
		printf("\n");
	printf("%.0f, %.0f, %.0f; ", point[0], point[1], point[2]);
	//printf("%2.0f ", point[2]);
}

void			print_array_points(float **array, int x, int y)
{
	int		i;
	int		size;

	size = x * y;
	i = -1;
	while (++i < size)
		print_point(array[i], i, x);
}
//TODO STOP

static void			parser_fdf(int fd, int x, int y, float **array)
{
	int			current_x;
	int			current_y;
	char		*line;
	char 		*temp;

	//if ((y = nb_lines(file) < 1))
	//	return (NULL); //set error pour savoir quel message d'erreur afficher
	current_y = 0;
	while (++current_y < y)
	{
		get_next_line(fd, &line);
		temp = line;
		current_x = -1;
		while (++current_x < x)
			temp = next_nbr(temp, array[current_y * x + current_x]);
		free(line);
	}
	//gestion des erreurs
}

#include <stdio.h>
#include <stdlib.h>

float			**get_points(char *file, t_env *env)
{
	char	*line;
	int		fd;
	float	**array;
	int		i;
	char	*temp;

	i = -1;
	env->y = nb_lines(file);
	fd = open(file, O_RDONLY);
	get_next_line(fd, &line);
	env->x = nb_points(line);
	temp = line;
	array = generate_array_points(env->x, env->y);
	while (++i < env->x)
		temp = next_nbr(temp, array[i]);
	free(line);
	parser_fdf(fd, env->x, env->y, array);
	//print_array_points(array, env->x, env->y);
	return (array);
}
