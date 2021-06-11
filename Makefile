# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 18:46:31 by abbelhac          #+#    #+#              #
#    Updated: 2021/06/11 19:52:38 by abbelhac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a 
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
SRCS =	msg.c \
		param_checker.c \
		stack.c \
		stack_op.c \
		stack_sort.c \
		clear.c \
		bubble_sort.c \
		utils.c \
		tools.c \
		get_next_line.c \
		get_next_line_utils.c

LIBFT = libft/libft.a
OBJ = $(SRCS:.c=.o)

all : $(NAME) run checker

$(NAME) : $(LIBFT) $(OBJ) $(HEADER)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(LIBFT) :
	make -C libft/

%.o: %.c
	gcc -c $(FLAGS) $<  $(HEADER)

run : $(NAME)
	gcc $(FLAGS) push_swap.c $(NAME) -o push_swap

checker : $(NAME)
	gcc $(FLAGS) checker.c $(NAME) -o checker

cleanlibft :
	make clean -C libft/

clean : cleanlibft
	rm $(OBJ)

fcleanlibft :
	make fclean -C libft/ 

fclean : fcleanlibft clean
	rm $(NAME)
	rm push_swap
	rm checker

re : fclean all