/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:12:23 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/09 20:22:39 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_read(t_push *ps)
{
	char	*line;
	int		ret;
	int		fd;

	ps->arr = NULL;
	line = NULL;
	fd = open("/home/abb/push_swap/test", O_RDWR);
	ret = get_next_line(fd, &line);
	while (ret)
	{
		printf("||%s||\n", line);
		free(line);
		line = NULL;
		ret = get_next_line(1, &line);
	}
}

int	main(int ac, char **av)
{
	t_push	ps;

	ps = (t_push){0};
	if (ac == 1)
		msg("Error\n", &ps);
	fill_stack(&ps, &av[1]);
	check_param(av, &ps);
	//print_stack(&ps);
	push_read(&ps);
}
