/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:01:46 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/05 21:32:16 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack(int data, t_push *ps)
{
	t_stack *new;
	t_stack *tmp;
	
	tmp = NULL;
	if(!(new = (t_stack *)malloc(sizeof(t_stack))))
		msg("Error!\nmalloc", ps);
	new->data = data;
	new->next = NULL;
	if (!ps->stack_a)
		ps->stack_a = new;
	else
	{
		tmp = ps->stack_a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return;
}

void	init(t_push *ps, int ac)
{
	ps->size = ac - 1;
	ps->stack_a = NULL;
	ps->stack_b = NULL;
}

void	print_stack(t_push *ps)
{
	t_stack *tmp;

	printf("\n\nSTACK A\n\n");
	tmp = ps->stack_a;
			while (tmp)
	{
		printf("|%d|\t|id : %d|\n", tmp->data, tmp->id);
		tmp = tmp->next;
	}
	printf("\n\nSTACK B\n\n");
	tmp = ps->stack_b;
	while (tmp)
	{
		printf("|%d|\t|id : %d|\n", tmp->data, tmp->id);
		tmp = tmp->next;
	}
	printf("\nend of print\n");
	printf("===================\n");
}

void	push_n(t_push *ps, char *s, int n)
{
	while (n--)
	push(ps, s);
}

int		main(int ac, char **av)
{
	t_push	ps;

	ps = (t_push){0};

	if (ac == 1)
		msg("invalid param", &ps);
	fill_stack(&ps, &av[1]);
	check_param(av, &ps);
	ps.size = stack_size(ps.stack_a);
	// sort_arr(&ps);
	// printf_arr(&ps);

	//  push_n(&ps, "pb", 4);
	  print_stack(&ps);
	// // stack_swap(&ps, "ss");
	// push_n(&ps, "pa", 100);
	// print_stack(&ps);
	// if (ps.stack_b)
	// 	printf("there is something in b");
	//get_key(&ps);
	stack_sort(&ps);
	print_stack(&ps);
	printf("\nmove num : %d\n", ps.counter);
	//printf("\nstack size : %d\n", (ps.size) / 4 * 3);
	// printf("\n size stack")
	// write(1, "done\n", 5);
	// while (1)
	// {
		
	// }
	// return(0);
}
