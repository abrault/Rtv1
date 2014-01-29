# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abrault <abrault@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 15:06:42 by abrault           #+#    #+#              #
#    Updated: 2013/12/22 13:19:46 by abrault          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Wextra -Werror

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memset.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdup.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  get_next_line.c \
	  ft_getTab2.c \
	  getCommand.c \
	  ft_strtok.c

SRC_O = ft_atoi.o \
	 ft_bzero.o \
	 ft_isalnum.o \
	 ft_isalpha.o \
	 ft_isascii.o \
	 ft_isdigit.o \
	 ft_isprint.o \
	 ft_memset.o \
	 ft_strcat.o \
	 ft_strchr.o \
	 ft_strcmp.o \
	 ft_strcpy.o \
	 ft_strdup.o \
	 ft_strlcat.o \
	 ft_strlen.o \
	 ft_strncat.o \
	 ft_strncmp.o \
	 ft_strcpy.o \
	 ft_strncpy.o \
	 ft_strnstr.o \
	 ft_strrchr.o \
	 ft_strstr.o \
	 ft_tolower.o \
	 ft_toupper.o \
	 ft_memccpy.o \
	 ft_memchr.o \
	 ft_memcmp.o \
	 ft_memcpy.o \
	 ft_memmove.o \
	 ft_putchar.o \
	 ft_putstr.o \
	 ft_putendl.o \
	 get_next_line.o \
	 ft_getTab2.o \
	 getCommand.o \
	 ft_strtok.o

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) $(SRC_O)
	ranlib $(NAME)

clean:
	/bin/rm -f $(SRC_O)

fclean:
	/bin/rm -f $(NAME)

re: fclean all
