/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:07:26 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/09 20:20:59 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# define BUFFER_SIZE 1

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
	int			key[12];
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_push;

void		msg(char *s, t_push *ps);
int			isnotnum(char *s);
void		split_check(t_push *ps, char **spliter);
void		check_param(char **av, t_push *ps);
void		stack_swap(t_push *ps, char *s);
void		push(t_push *ps, char *s);
void		rotate(t_stack **stack, int r);
void		stack_rotate(t_push *ps, char *s);
void		fill_stack(t_push *ps, char **av);
t_stack		*last_stack(t_stack *node, int r);
int			stack_size(t_stack *stack);
void		stack_sort(t_push *ps);
void		init_stack_id(t_push *ps);
void		free_spliter(char **spliter);
void		free_spliter(char **spliter);
void		ft_clear(t_push *ps);
void		printf_arr(t_push *ps);
void		fill_arr(t_push *ps);
void		sort_arr(t_push *ps);
int			is_sorted(t_stack *stack);
t_stack		*get_min(t_stack *stack);
t_stack		*get_max(t_stack *stack);
void		get_key(t_push *ps);
t_stack		*get_under_key(t_stack *stack, int i);
void		push_min_to_b(t_push *ps);
void		push_to_b(t_push *ps, t_stack *smaller);
void		push_to_a(t_push *ps, t_stack *max);
void		check_param(char **av, t_push *ps);
void		print_stack(t_push *ps);
void		push_n(t_push *ps, char *s, int n);
char		*substr(char *s, unsigned int start, size_t len);
char		*join(char *s1, char const *s2);
int			get_next_line(int fd, char **line);

#endif
