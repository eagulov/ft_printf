# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/16 13:26:18 by eagulov           #+#    #+#              #
#    Updated: 2019/03/18 19:07:01 by eagulov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a
SRC = $(wildcard *.c)
LIBFT = libft/libft.a
OBJ = $(patsubst %.c,%.o,$(wildcard *.c))
DAMN = \033[0;92m

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
			@ar rc $(NAME) $(OBJ)
			@echo "$(DAMN)Daaaaamn, it's compiled"

$(LIBFT) :
			@make -C libft
			@echo "$(DAMN)Yo, libft was compiled"

%.o : %.c
			@gcc  $< -o $@ -Wall -Wextra -Werror -g -c

clean :
			@rm -rf $(OBJ)
			@make clean -C libft
			@echo "$(DAMN)Wow, all obj is deleted"

fclean : clean
			@rm -rf $(NAME)
			@make fclean -C libft
			@echo "$(DAMN)No way, everything is cleaned"

re : fclean all

.PHONY : all clean fclean re
