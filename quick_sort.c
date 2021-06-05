/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:19:08 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/04 17:39:13 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_arr(t_push *ps)
{
	int	i;

	i = 0;
	while (i < ps->size)
	{
		printf("|%d|\t", ps->arr[i]);
		i++;
	}
	write(1, "\n", 1);
}

void	fill_arr(t_push *ps)
{
	t_stack	*stack;
	int		i;

	ps->arr = (int *)malloc(sizeof(int) * ps->size);
	if (!ps->arr)
		msg("Error\n malloc in quicksort\n", ps);
	stack = ps->stack_a;
	i = 0;
	while (stack && i < ps->size)
	{
		ps->arr[i] = stack->data;
		stack = stack->next;
		i++;
	}
}

int	partition(t_push *ps, int start, int end)
{
	int	pivot;
	int	val;

	pivot = start;
	val = ps->arr[pivot];
	while (start < end)
	{
		while (ps->arr[start] <= val)
			start++;
		while (ps->arr[end] > val)
			end--;
		if (start < end)
			ft_swap(&ps->arr[start], &ps->arr[end]);
	}
	ft_swap(&ps->arr[pivot], &ps->arr[end]);
	return (end);
}

void	quick_sort(t_push *ps, int start, int end)
{
	int	splitpoint;

	if (start < end)
	{
		splitpoint = partition(ps, start, end);
		quick_sort(ps, start, splitpoint - 1);
		quick_sort(ps, splitpoint + 1, end);
	}
}

void	sort_arr(t_push *ps)
{
	fill_arr(ps);
	quick_sort(ps, 0, ps->size - 1);
}
