/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:37:40 by abbelhac          #+#    #+#             */
/*   Updated: 2021/05/27 21:45:33 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	msg(char *s, t_push *ps)
{
	ft_putstr_fd(s, 2);
	ft_clear(ps);
	if (ps->stack_a)
		ft_putstr_fd("stack 3amer\n", 1);
	exit (1);
}
