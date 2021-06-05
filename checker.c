/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 19:51:42 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/04 14:39:06 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	isnotnum(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	is_duplicate(t_stack *stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int	c;

	tmp1 = stack;
	while (tmp1)
	{
		c = 0;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp1->data == tmp2->data)
				c++;
			if (c > 1)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int	int_range(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	if (ft_strlen(&s[i]) > 10)
		return (1);
	if ((s[0] == '-' && ft_atoi(s) > 0)
		|| (s[0] != '-' && ft_atoi(s) < 0))
		return (1);
	return (0);
}

void	check_param(char **av, t_push *ps)
{
	int		i;
	int		j;
	char	**spliter;
	
	i = 1;
	while (av[i])
	{
		j = 0;
		spliter = ft_split(av[i], ' ');
		while (spliter[j])
		{
			if (isnotnum(spliter[j]))
			 	msg("Error!\nparameter not number", ps);
			if (int_range(spliter[j]))
				msg("Error!\nint overflow", ps);
			if (is_duplicate(ps->stack_a))
				msg("Error!\nduplicate number\n", ps);
			if (is_sorted(ps->stack_a))
				msg("sorted param\n", ps);
			j++;
			if (!spliter[j])
				free_spliter(spliter);
		}
		i++;
	}
}
