/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:25:03 by abbelhac          #+#    #+#             */
/*   Updated: 2021/05/27 21:13:58 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mpointer;

	mpointer = malloc(count * size);
	if (!mpointer)
		return (0);
	ft_bzero(mpointer, (count * size));
	return (mpointer);
}
