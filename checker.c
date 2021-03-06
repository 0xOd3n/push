/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:12:23 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/18 16:19:23 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handler(t_push *ps, char *op)
{
	if ((!ft_strcmp(op, "sa")) || !(ft_strcmp(op, "sb"))
		|| !(ft_strcmp(op, "ss")))
		stack_swap(ps, op, 0);
	else if ((!ft_strcmp(op, "pa")) || (!ft_strcmp(op, "pb")))
		push(ps, op, 0);
	else if ((!ft_strcmp(op, "ra")) || !(ft_strcmp(op, "rb"))
		|| (!ft_strcmp(op, "rr")))
		stack_rotate(ps, op, 0);
	else if ((!ft_strcmp(op, "rra")) || (!ft_strcmp(op, "rrb"))
		|| !ft_strcmp(op, "rrr"))
		stack_rotate(ps, op, 0);
	else
		msg("\e[1;31mError\e[0m\n", ps);
}

void	push_read(t_push *ps)
{
	char	*line;
	int		ret;

	ps->arr = NULL;
	line = NULL;
	ret = get_next_line(0, &line);
	while (ret)
	{
		handler(ps, line);
		free(line);
		line = NULL;
		ret = get_next_line(0, &line);
	}
	if (line)
		free(line);
}

int	main(int ac, char **av)
{
	t_push	ps;

	ps = (t_push){0};
	if (ac == 1)
		return (0);
	fill_stack(&ps, &av[1]);
	check_param(av, &ps);
	push_read(&ps);
	if (is_sorted(ps.stack_a))
		ft_putstr_fd("\033[1;32mOK\033[0m\n", 1);
	else
		ft_putstr_fd("\033[1;31mKO\033[0m\n", 1);
	ft_clear(&ps);
}
