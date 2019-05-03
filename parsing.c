/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:10:51 by cbretagn          #+#    #+#             */
/*   Updated: 2019/05/03 18:09:05 by cbretagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "./libft/libft.h"
#include "get_next_line.h"
#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int			nb_points(char *str)
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
	int		ret;
	int		lines;
	char	buffer[4097];

	lines = 0;
	fd = open(file, O_RDONLY);
	while ((ret = read(fd, buffer, 4096)) > 0)
	{
		buffer[ret] = '\0';
		i = -1;
		while (buffer[++i])
		{
			if (buffer[i] == '\n')
			{
				if (i - 1 >= 0 && buffer[i - 1] == '\n')
					return (close_fd(fd, lines));
				lines++;
			}
		}
	}
	return (close_fd(fd, lines));
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
	if (!(*str >= '0' && *str <= '9'))
		return (NULL);
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	current[2] = nb * sign * 5;
	return (str);
}

static int			parser_fdf(int fd, int x, int y, float **array)
{
	int			current_x;
	int			current_y;
	char		*line;
	char		*temp;

	current_y = 0;
	while (++current_y < y)
	{
		get_next_line(fd, &line);
		temp = line;
		if (nb_points(line) != x)
			return (-1);
		current_x = -1;
		while (++current_x < x)
		{
			if (!(temp = next_nbr(temp, array[current_y * x + current_x])))
				return (-1);
		}
		free(line);
	}
	return (0);
}

float				**get_points(char *file, t_env *env)
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
	if (env->y < 1 || env->x < 2)
		return (NULL);
	temp = line;
	array = generate_array_points(env->x, env->y);
	while (++i < env->x)
		temp = next_nbr(temp, array[i]);
	free(line);
	if (parser_fdf(fd, env->x, env->y, array) == -1)
		return (NULL);
	return (array);
}
