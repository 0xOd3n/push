/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 20:19:40 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/11 20:01:12 by abbelhac         ###   ########.fr       */
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
