/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:02:31 by abbelhac          #+#    #+#             */
/*   Updated: 2019/11/16 23:24:12 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		next_c(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}
