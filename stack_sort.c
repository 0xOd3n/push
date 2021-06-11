/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:09:07 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/11 18:56:09 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_of_3(t_push *ps)
{
	int	first;
	int	second;
	int	third;

	first = ps->stack_a->data;
	second = ps->stack_a->next->data;
	if (ps->stack_a->next->next)
		third = ps->stack_a->next->next->data;
	if ((ps->size == 2 && first > second) || (first > second && first < third))
		stack_swap(ps, "sa", 1);
	else if (second < third && first > third)
		stack_rotate(ps, "ra", 1);
	else if (first < second && first > third)
		stack_rotate(ps, "rra", 1);
	else if ((first > second) && (second > third))
	{
		stack_swap(ps, "sa", 1);
		stack_rotate(ps, "rra", 1);
	}
	else if (first < third && second > third)
	{
		stack_swap(ps, "sa", 1);
		stack_rotate(ps, "ra", 1);
	}
}

void	case_of_10(t_push *ps)
{
	t_stack	*min;
	int		med;

	while (!is_sorted(ps->stack_a) || (is_sorted(ps->stack_a) && ps->stack_b))
	{
		if ((stack_size(ps->stack_a)) <= 3)
			case_of_3(ps);
		else
		{
			min = get_min(ps->stack_a);
			med = (stack_size(ps->stack_a) / 2);
			while (ps->stack_a->data != min->data)
			{
				if (med >= min->id)
					stack_rotate(ps, "ra", 1);
				else
					stack_rotate(ps, "rra", 1);
				min = get_min(ps->stack_a);
			}
			if (!(is_sorted(ps->stack_a)) && ps->stack_a->data == min->data)
				push(ps, "pb", 1);
		}
		while (is_sorted(ps->stack_a) && ps->stack_b)
			push(ps, "pa", 1);
	}
}

t_stack	*get_under_key(t_stack *stack, int i)
{
	while (stack)
	{
		if (stack->data <= i)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	case_of_100(t_push *ps)
{
	t_stack	*min;
	t_stack	*max;

	sort_arr(ps);
	get_key(ps);
	push_min_to_b(ps);
	while (ps->stack_a)
	{
		min = get_min(ps->stack_a);
		push_to_b(ps, min);
	}
	while (ps->stack_b)
	{
		max = get_max(ps->stack_b);
		push_to_a(ps, max);
		if (!ps->stack_b)
			break ;
	}
}

void	stack_sort(t_push *ps)
{
	if (ps->size <= 10)
		case_of_10(ps);
	else if (ps->size > 10)
		case_of_100(ps);
	free (ps->arr);
}
