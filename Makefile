# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrault <abrault@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/02 13:50:21 by abrault           #+#    #+#              #
#    Updated: 2014/02/16 21:11:48 by abrault          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = src/main.c \
	  src/mlx_pixel_put_to_image.c \
	  src/ini.c \
	  src/hook.c \
	  src/draw_image.c \
	  src/scene.c \
	  src/ray_tracing.c \
	  src/tools.c \
	  src/find_inter.c

LIB = libft/libft.a

LIB_INC = libft/includes/ -I/usr/X11R6/include

LIB_DIR = libft

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g

MFLAGS = -L/usr/X11/lib -lXext -lX11 -lmlx

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(MFLAGS) $(LIB)

$(LIB):
	cd $(LIB_DIR) && $(MAKE)

%.o: %.c
	gcc -c $(CFLAGS) -I./include/ $< -o $@ -I . -I $(LIB_INC)

clean:
	cd $(LIB_DIR) && $(MAKE) clean
	rm -rf $(OBJ)


fclean: clean
	cd $(LIB_DIR) && $(MAKE) fclean
	rm -rf $(NAME)

re: fclean all


re: fclean all
