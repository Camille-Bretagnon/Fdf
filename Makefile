# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbretagn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 16:54:48 by cbretagn          #+#    #+#              #
#    Updated: 2019/05/03 20:00:24 by cbretagn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

SRC			= main.c\
			  parsing.c\
			  get_next_line.c\
			  fill_image.c\
			  matrix.c\
			  event.c\
			  event_part2.c\
			  clipping.c\
			  parsing_part2.c\

OBJS		:= $(SRC:.c=.o)

LIB_PATH	= libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

MLX_FLAGS	= -lmlx -framework OpenGL -framework Appkit

.PHONY		: all clean fclean re

all			: $(NAME)

$(NAME)		: $(OBJS)
	make -C ./libft/
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_PATH) $(MLX_FLAGS)

clean		:
	rm -f $(OBJS)
	make clean -C ./libft/

fclean		: clean
	rm -f $(NAME)
	make fclean -C ./libft/

re 			: fclean all
