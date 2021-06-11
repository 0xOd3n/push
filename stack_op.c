/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:25:25 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/11 18:53:29 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_to_b(t_push *ps)
{
	t_stack	*smaller;
	int		i;

	i = 0;
	while (i < ps->div)
	{
		while (1)
		{
			smaller = get_under_key(ps->stack_a, ps->key[i]);
			if (!smaller)
				break ;
			else
				push_to_b(ps, smaller);
		}
		i++;
	}
}

void	stack_swap(t_push *ps, char *s, int bool)
{
	if (!ft_strcmp(s, "sa") && ps->stack_a && ps->stack_a->next)
		ft_swap(&ps->stack_a->data, &ps->stack_a->next->data);
	else if (!ft_strcmp(s, "sb") && ps->stack_b && ps->stack_b->next)
		ft_swap(&ps->stack_b->data, &ps->stack_b->next->data);
	else if (!ft_strcmp(s, "ss") && ps->stack_a && ps->stack_b
		&& ps->stack_a->next && ps->stack_b->next)
	{
		ft_swap(&ps->stack_a->data, &ps->stack_a->next->data);
		ft_swap(&ps->stack_b->data, &ps->stack_b->next->data);
	}
	if (bool)
	{
		ft_putstr_fd(s, 1);
		write(1, "\n", 1);
	}
	ps->counter++;
}

void	push(t_push *ps, char *s, int bool)
{
	t_stack		*tmp;

	if (!ft_strcmp(s, "pb") && ps->stack_a)
	{
		tmp = ps->stack_b;
		ps->stack_b = ps->stack_a;
		ps->stack_a = ps->stack_a->next;
		ps->stack_b->next = tmp;
	}
	else if (!ft_strcmp(s, "pa") && ps->stack_b)
	{
		tmp = ps->stack_a;
		ps->stack_a = ps->stack_b;
		ps->stack_b = ps->stack_b->next;
		ps->stack_a->next = tmp;
	}
	if (bool)
	{
		ft_putstr_fd(s, 1);
		write(1, "\n", 1);
	}
	init_stack_id(ps);
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

void	stack_rotate(t_push *ps, char *s, int bool)
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
	if (bool)
	{
		ft_putstr_fd(s, 1);
		write(1, "\n", 1);
	}
	init_stack_id(ps);
	ps->counter++;
}
