/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 14:58:55 by abbelhac          #+#    #+#             */
/*   Updated: 2019/10/27 23:37:15 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		dstlen;
	int			i;

	i = 0;
	len = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (!dst && size == 0)
		return (len);
	if (size <= dstlen)
		return (len + size);
	len += dstlen;
	while (src[i] != '\0' && dstlen < size - 1)
	{
		dst[dstlen] = src[i];
		i++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (len);
}
