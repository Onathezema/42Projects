# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: winorth <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 12:02:49 by winorth           #+#    #+#              #
#    Updated: 2019/08/26 12:15:32 by winorth          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#REMOVE -g flag from ALL MAKEFILES

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra

FILES = src/ft_printf.c \
	src/utilities.c \
	src/parse_handlers.c \
	src/handler_arr.c \
	src/handle_bho.c \
	src/handle_chars.c \
	src/handle_intlong.c \
	src/handle_misc.c \
	src/handle_unsigned.c \
	src/handle_strs.c \

LIBFT = libft/

all: $(NAME)

libft:
	@$(MAKE) -C $(LIBFT) $(OBJS)

$(NAME): libft
	@$(CC) $(CFLAGS) -c $(FILES)
	@ar rcs $(NAME) *.o $(LIBFT)*.o
	@ranlib $(NAME)
	@rm *.o

clean:
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

test:
	$(CC) $(CFLAGS) libft/libft.a src/*.c -I.

.PHONY: all libft $(NAME) clean fclean re
