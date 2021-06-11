/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:01:46 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/11 19:27:21 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
