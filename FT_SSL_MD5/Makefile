# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: winorth <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/08 16:41:09 by winorth           #+#    #+#              #
#    Updated: 2019/10/14 16:42:28 by winorth          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRC = src/*.c

I = -I include/

O = *.o

L = libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(CFLAGS) -c $(I) $(SRC)
	@gcc $(CFLAGS) $(O) $(L) -o $(NAME)
	@rm *.o

clean:
	@make -C libft clean
	@rm -rf $(O)

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)

re: fclean all
