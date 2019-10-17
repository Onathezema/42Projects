# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: winorth <winorth@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/14 12:11:20 by winorth           #+#    #+#              #
#    Updated: 2019/10/14 16:43:04 by winorth          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c

O = *.o

I = -I ./include

SRC = src/*.c \
      src/printf/*.c \
	  src/getopt/*.c \
	  src/memmgr/*.c \

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(I) $(SRC)
	@ar rc $(NAME) $(O)
	@rm $(O)

clean:
	@rm -f $(O)

fclean: clean
	@rm -f $(NAME)

re: fclean all
