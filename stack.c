/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:30:25 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/01 19:04:41 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_arg_split(t_push *ps, t_stack **stack, char *av)
{
	char	**spliter;
	int		i;

	i = 0;
	spliter = ft_split(av, ' ');
	while (spliter[i])
	{
		(*stack)->data = ft_atoi(spliter[i]);
		i++;
		if (!spliter[i])
			break ;
		(*stack)->next = (t_stack *)malloc(sizeof(t_stack));
		if (!(*stack)->next)
			msg("Error\nmalloc in split arg", ps);
		(*stack) = (*stack)->next;
	}
	free_spliter(spliter);
}

void	fill_stack(t_push *ps, char **av)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	ps->stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!ps->stack_a)
		msg("Error!\nmalloc", ps);
	tmp = ps->stack_a;
	tmp->next = NULL;
	while (av[i])
	{
		stack_arg_split(ps, &tmp, av[i]);
		i++;
		if (!av[i])
			break ;
		tmp->next = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
			msg("Error!\nmalloc", ps);
		tmp = tmp->next;
	}
	tmp->next = NULL;
	init_stack_id(ps);
}

void	init_stack_id(t_push *ps)
{
	int		id;
	t_stack	*p;

	id = 0;
	p = ps->stack_a;
	while (p)
	{
		p->id = ++id;
		p = p->next;
	}
	id = 0;
	p = ps->stack_b;
	while (p)
	{
		p->id = ++id;
		p = p->next;
	}
}

int	stack_size(t_stack *stack)
{
	int		c;
	t_stack	*tmp;

	tmp = stack;
	c = 0;
	while (tmp)
	{
		tmp = tmp->next;
		c++;
	}
	return (c);
}

t_stack	*last_stack(t_stack *node, int r)
{
	while (node->next)
	{
		if ((r) && (!node->next->next))
			return (node);
		node = node->next;
	}
	return (node);
}
