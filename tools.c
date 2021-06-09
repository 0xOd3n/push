/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:19:40 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/09 20:21:15 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_param(char **av, t_push *ps)
{
	int		i;
	char	**spliter;

	i = 1;
	while (av[i])
	{
		spliter = ft_split(av[i], ' ');
		split_check(ps, spliter);
		i++;
	}
}

void	print_stack(t_push *ps)
{
	t_stack	*tmp;

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
