/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:09:07 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/05 21:54:56 by abbelhac         ###   ########.fr       */
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
		stack_swap(ps, "sa");
	else if (second < third && first > third)
		stack_rotate(ps, "ra");
	else if (first < second && first > third)
		stack_rotate(ps, "rra");
	else if ((first > second) && (second > third))
	{
		stack_swap(ps, "sa");
		stack_rotate(ps, "rra");
	}
	else if (first < third && second > third)
	{
		stack_swap(ps, "sa");
		stack_rotate(ps, "ra");
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
					stack_rotate(ps, "ra");
				else
					stack_rotate(ps, "rra");
				min = get_min(ps->stack_a);
			}
			if (!(is_sorted(ps->stack_a)) && ps->stack_a->data == min->data)
				push(ps, "pb");
		}
		while (is_sorted(ps->stack_a) && ps->stack_b)
			push(ps, "pa");
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
				break;
			else
				push_to_b(ps, smaller);
		}
		i++;
	}
}

void	get_key(t_push *ps)
{
	int	key;
	int	med;
	int	i;
	
		if (ps->size > 10 && ps->size <= 100)
			key = (ps->size - 1) / 4;
		else
			key = (ps->size - 1) / 8;
	i = 0;
	med = key;
	key++;
	ps->div = (ps->size - 1) / key;
	 while (i < ps->div)
	 {
	 	ps->key[i] = ps->arr[med];
	 	printf("med id|%d|\t", ps->key[i]);
	 	//printf("\nmed = %d\n", ps->div);
		med = med + key;
	 	i++;
	 }
	printf("\ni_key = %d\n", key);
}

void	case_of_100(t_push *ps)
{	
	sort_arr(ps);
	get_key(ps);
	push_min_to_b(ps);
}

void	stack_sort(t_push *ps)
{
	if (ps->size <= 10)
		case_of_10(ps);
	else if (ps->size > 10 && ps->size <= 100)
		case_of_100(ps);
}
