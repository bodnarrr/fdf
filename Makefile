# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abodnar <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 12:17:53 by abodnar           #+#    #+#              #
#    Updated: 2018/03/18 14:43:23 by abodnar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = libftprintf.a

SRCS =	main.c ft_fdf_parse.c ft_initial_coords.c ft_print_points.c \
		ft_fdf_hooks.c ft_clear_lines.c
		

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADERS = *.h

all: $(NAME)

%.o : %.c
	@gcc -g -I. -I./libftprintf $(FLAGS) -c $< -o $@

$(NAME): $(LIB) $(OBJECTS) $(HEADERS)
	@gcc -g -lmlx -framework OpenGL -framework AppKit -o $@ -I. -I./libftprintf $(OBJECTS) $(LIB)
	@echo "\033[1;32mFDF is ready\033[0m"

$(LIB):
	@make -C ./libftprintf/
	@cp ./libftprintf/libftprintf.a .

clean:
	@make fclean -C ./libftprintf
	@rm -f *.o
	@rm -f libftprintf.a
	@echo "\033[1;32mObject files FDF were removed\033[0m"

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re
