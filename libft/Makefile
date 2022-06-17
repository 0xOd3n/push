#
#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/26 15:14:32 by abbelhac          #+#    #+#              #
#    Updated: 2019/11/11 19:58:52 by abbelhac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRCS =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_swap.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_strcat.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_count_word.c \
		next_c.c \
		next_word.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strndup.c
		

BONUS = ft_lstadd_front_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c

OBJ = $(SRCS:.c=.o)
INCLUDE = libft.h

OBJ_BON= $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	@ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_BON)
	@ar rcs $(NAME) $(OBJ) $(OBJ_BON)

%.o: %.c
	@gcc $(FLAGS) -c $<  $(INCLUDE)

clean:
	@rm -f $(OBJ) $(OBJ_BON)

fclean: clean
	@rm -f $(NAME)

re: fclean all
