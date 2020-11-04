# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahakanen <aleksi.hakanen94@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/16 05:19:03 by ahakanen          #+#    #+#              #
#    Updated: 2020/11/04 11:52:15 by ahakanen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBF = ./libft/
LIB = ./libft/libft.a
MINI = -I /usr/local/include -L /usr/local/lib/ -lmlx -lX11 -lXext -lm \
		-lpthread
HEADER_PATH = ./header/
SRC = main.c openwindow.c screentocomplex.c deal_key.c deal_mouse.c \
		deal_mousemove.c changecolor.c psych.c mandelbrot.c julia.c \
		moose.c

all: $(NAME)

$(NAME):
	make -C $(LIBF)
	$(CC) $(FLAGS) -o $(NAME) $(SRC) $(LIB) -I $(HEADER_PATH) $(MINI)

clean:
	make -C $(LIBF) clean

fclean:
	rm -rf $(NAME)
	make -C $(LIBF) fclean

re: fclean all

.PHONY: all clean fclean re
