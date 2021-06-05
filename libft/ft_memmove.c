/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:39:26 by abbelhac          #+#    #+#             */
/*   Updated: 2019/10/27 20:53:06 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*s;
	char		*d;

	s = (char *)src;
	d = (char *)dst;
	if (src < dst)
	{
		while (n)
		{
			n--;
			d[n] = s[n];
		}
	}
	ft_memcpy(dst, src, n);
	return (dst);
}
