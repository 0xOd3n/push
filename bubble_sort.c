/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:19:08 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/18 16:42:52 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	bubble_sort(t_push *ps)
{
	int	i;
	int	*tmp;
	int	exec;

	tmp = ps->arr;
	exec = 1;
	while (exec)
	{
		exec = 0;
		i = 0;
		while ((i + 1) < ps->size)
		{
			if (tmp[i] > tmp[i + 1])
			{
				exec = 1;
				ft_swap(&tmp[i], &tmp[i + 1]);
			}
			i++;
		}
	}
}

void	sort_arr(t_push *ps)
{
	fill_arr(ps);
	bubble_sort(ps);
}
