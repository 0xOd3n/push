/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 22:06:45 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/08 22:10:07 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clear(t_push *ps)
{
	t_stack	*tmp;

	while (ps->stack_a)
	{
		tmp = ps->stack_a;
		ps->stack_a = ps->stack_a->next;
		free (tmp);
	}
	while (ps->stack_b)
	{
		tmp = ps->stack_b;
		ps->stack_b = ps->stack_b->next;
		free(tmp);
	}
	ps->stack_a = NULL;
	ps->stack_b = NULL;
}

void	free_spliter(char **spliter)
{
	int	i;

	i = 0;
	while (spliter && spliter[i])
	{
		free(spliter[i]);
		i++;
	}
	free(spliter);
	spliter = NULL;
}
