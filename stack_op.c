/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:25:25 by abbelhac          #+#    #+#             */
/*   Updated: 2021/05/31 18:28:07 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_push *ps, char *s)
{
	if (!ft_strcmp(s, "sa") && ps->stack_a && ps->stack_a->next)
	{
		ft_swap(&ps->stack_a->data, &ps->stack_a->next->data);
		write(1, "sa\n", 3);
	}
	else if (!ft_strcmp(s, "sb") && ps->stack_b && ps->stack_b->next)
	{
		ft_swap(&ps->stack_b->data, &ps->stack_b->next->data);
		write(1, "sb\n", 3);
	}
	else if (!ft_strcmp(s, "ss") && ps->stack_a && ps->stack_b
		&& ps->stack_a->next && ps->stack_b->next)
	{
		ft_swap(&ps->stack_a->data, &ps->stack_a->next->data);
		ft_swap(&ps->stack_b->data, &ps->stack_b->next->data);
		write(1, "ss\n", 3);	
	}
	ps->counter++;
}

void	push(t_push *ps, char *s)
{
	t_stack		*tmp;

	if (!ft_strcmp(s, "pb") && ps->stack_a)
	{
		tmp = ps->stack_b;
		ps->stack_b = ps->stack_a;
		ps->stack_a = ps->stack_a->next;
		if (!tmp)
			ps->stack_b->next = NULL;
		else
			ps->stack_b->next = tmp;
		write(1, "pb\n", 3);
	}
	else if (!ft_strcmp(s, "pa") && ps->stack_b)
	{
		tmp = ps->stack_a;
		ps->stack_a = ps->stack_b;
		ps->stack_b = ps->stack_b->next;
		if (!tmp)
			ps->stack_a->next = NULL;
		ps->stack_a->next = tmp;
		write(1, "pa\n", 3);
	}
	init_satck_id(ps);
	ps->counter++;
}

void	rotate(t_stack **stack, int r)
{
	t_stack	*tmp;
	t_stack	*lst;

	if ((!r) && (*stack) && (*stack)->next)
	{
		tmp = (*stack);
		lst = last_stack((*stack), r);
		(*stack) = tmp->next;
		lst->next = tmp;
		lst->next->next = NULL;
	}
	else if ((r) && (*stack) && (*stack)->next)
	{
		tmp = last_stack((*stack), 0);
		lst = last_stack((*stack), r);
		lst->next = NULL;
		tmp->next = (*stack);
		(*stack) = tmp;
	}
}

void	stack_rotate(t_push *ps, char *s)
{
	if (!ft_strcmp(s, "ra"))
		rotate(&ps->stack_a, 0);
	else if (!ft_strcmp(s, "rb"))
		rotate(&ps->stack_b, 0);
	else if (!ft_strcmp(s, "rr"))
	{
		rotate(&ps->stack_a, 0);
		rotate(&ps->stack_b, 0);
	}
	else if (!ft_strcmp(s, "rra"))
		rotate(&ps->stack_a, 1);
	else if (!ft_strcmp(s, "rrb"))
		rotate(&ps->stack_b, 1);
	else if (!ft_strcmp(s, "rrr"))
	{
		rotate(&ps->stack_a, 1);
		rotate(&ps->stack_b, 1);
	}
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	init_satck_id(ps);
	ps->counter++;
}