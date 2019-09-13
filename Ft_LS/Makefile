# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: winorth <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/08 16:41:09 by winorth           #+#    #+#              #
#    Updated: 2019/09/09 13:30:17 by winorth          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror -g

SRC = src/*.c

I = -I include/

O = *.o

L = libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(CFLAGS) -c $(I) $(SRC)
	@gcc $(CFLAGS) $(O) $(L) -o $(NAME)

clean:
	@make -C libft clean
	@rm -rf $(O)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean all
