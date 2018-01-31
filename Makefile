#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 22:53:24 by bvan-dyc          #+#    #+#              #
#    Updated: 2016/01/28 15:59:59 by bvan-dyc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=fractol

CFLAGS=-Wall -Wextra -Werror

SRC=src/main.c src/keyhook.c src/palette.c src/tools.c src/display.c src/fractals.c src/mouse.c

OBJS=main.o keyhook.o tools.o palette.o display.o fractals.o mouse.o

$(NAME):
	make -C libft/
	gcc $(CFLAGS) -I /usr/X11/include -L libft/ -lft -l mlx \
	-framework OpenGL -framework AppKit $(SRC) -o $(NAME)

all: $(NAME)

clean:
	rm -rf libft/*.o
	rm -rf $(OBJS)

fclean: clean
	rm -rf libft/libft.a rm -rf libft/*.o
	rm -rf $(NAME) rm -rf $(OBJS)

re: fclean all

.PHONY: clean fclean re all
