/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:01:46 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/08 22:10:43 by abbelhac         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_push	ps;

	ps = (t_push){0};
	if (ac == 1)
		msg("Error\n", &ps);
	fill_stack(&ps, &av[1]);
	check_param(av, &ps);
	ps.size = stack_size(ps.stack_a);
	stack_sort(&ps);
	ft_clear(&ps);
}
