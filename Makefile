# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 18:46:31 by abbelhac          #+#    #+#              #
#    Updated: 2021/06/18 17:12:14 by abbelhac         ###   ########.fr        #
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
PUSH = push_swap
CHECKER = checker

LIBFT = libft/libft.a
OBJ = $(SRCS:.c=.o)

all : $(NAME) $(PUSH) $(CHECKER)

$(NAME) : $(LIBFT) $(OBJ) $(HEADER)
	@cp $(LIBFT) $(NAME)
	@ar -rcs $(NAME) $(OBJ)

$(LIBFT) :
	@make -C libft/

%.o: %.c
	@$(CC) -c $(FLAGS) $^ $(HEADER)

$(PUSH) : $(NAME) push_swap.c
	@$(CC) -g $(FLAGS) push_swap.c $(NAME) -o $(PUSH)

$(CHECKER) : $(NAME) checker.c
	@$(CC) $(FLAGS) checker.c $(NAME) -o $(CHECKER)

cleanlibft :
	@make clean -C libft/

clean : cleanlibft
	@rm $(OBJ)
	@echo "clean"

fcleanlibft :
	@make fclean -C libft/ 

fclean : fcleanlibft clean
	@rm $(NAME)
	@rm push_swap
	@rm checker
	@echo "fclean"

re : fclean all