/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:07:26 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/04 19:10:43 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int					data;
	struct s_stack		*next;
	int					id;
}						t_stack;

typedef struct s_push
{
	int			size;
	int			counter;
	int			div;
	int			*arr;
	int			key[8];
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_push;

void		msg(char *s, t_push *ps);
int			isnotnum(char *s);
void		check_param(char **av, t_push *ps);
void		stack_swap(t_push *ps, char *s);
void		push(t_push *ps, char *s);
void		rotate(t_stack **stack, int r);
void		stack_rotate(t_push *ps, char *s);
void		fill_stack(t_push *ps, char **av);
t_stack		*last_stack(t_stack *node, int r);
int			stack_size(t_stack *stack);
void		stack_sort(t_push *ps);
void		init_satck_id(t_push *ps);
void		free_spliter(char **spliter);
void		free_spliter(char **spliter);
void    	ft_clear(t_push *ps);
void		printf_arr(t_push *ps);
void		fill_arr(t_push *ps);
void		sort_arr(t_push *ps);
int			is_sorted(t_stack *stack);
t_stack		*get_min(t_stack *stack);
t_stack		*get_max(t_stack *stack);
void		get_key(t_push *ps);
#endif
