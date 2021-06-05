/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 00:44:30 by abbelhac          #+#    #+#             */
/*   Updated: 2021/05/28 21:47:44 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *string, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
		return ((char *)string);
	while (string[i] != '\0' && (i < len))
	{
		j = 0;
		while (string[i + j] == needle[j] && ((i + j) < len))
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)string + i);
		}
		i++;
	}
	return (0);
}
