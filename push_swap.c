/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:01:46 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/18 16:21:11 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push	ps;

	ps = (t_push){0};
	if (ac == 1)
		return (0);
	fill_stack(&ps, &av[1]);
	check_param(av, &ps);
	if (is_sorted(ps.stack_a))
	{
		ft_clear(&ps);
		exit(0);
	}
	ps.size = stack_size(ps.stack_a);
	stack_sort(&ps);
	ft_clear(&ps);
}
