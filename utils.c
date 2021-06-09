/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:41:02 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/09 20:03:32 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (min->data > stack->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (max->data < stack->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	get_key(t_push *ps)
{
	int	key;
	int	med;
	int	i;

	if (ps->size > 10 && ps->size <= 100)
		key = (ps->size - 1) / 5;
	else
		key = (ps->size - 1) / 12;
	i = 0;
	med = key;
	key++;
	ps->div = (ps->size - 1) / key;
	while (i < ps->div)
	{
		ps->key[i] = ps->arr[med];
		med = med + key;
		i++;
	}
}

void	push_to_a(t_push *ps, t_stack *max)
{
	int	med;

	med = stack_size(ps->stack_b) / 2;
	while (ps->stack_b->data != max->data)
	{
		if (med >= max->id)
			stack_rotate(ps, "rb");
		else
			stack_rotate(ps, "rrb");
	}
	if (ps->stack_b->data == max->data)
		push(ps, "pa");
}

void	push_to_b(t_push *ps, t_stack *smaller)
{
	int	med;

	med = stack_size(ps->stack_a) / 2;
	while (ps->stack_a->data != smaller->data)
	{
		if (med >= smaller->id)
			stack_rotate(ps, "ra");
		else
			stack_rotate(ps, "rra");
	}
	if (ps->stack_a->data == smaller->data)
		push(ps, "pb");
}
