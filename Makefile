# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/18 18:46:31 by abbelhac          #+#    #+#              #
#    Updated: 2021/06/04 14:47:50 by abbelhac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a 
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = push_swap.h
SRCS = push_swap.c \
		msg.c \
		checker.c \
		stack.c \
		stack_op.c \
		stack_sort.c \
		clear.c \
		quick_sort.c \
		utils.c

LIBFT = libft/libft.a
OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ) $(HEADER)
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ)

$(LIBFT) :
	make -C libft/

%.o: %.c
	gcc -c $(FLAGS) $<  $(HEADER)

run : $(NAME)
	gcc $(FLAGS) $(NAME) -o push

cleanlibft :
	make clean -C libft/

clean : cleanlibft
	rm $(OBJ)

fcleanlibft :
	make fclean -C libft/ 

fclean : fcleanlibft clean
	rm $(NAME)

re : fclean all run