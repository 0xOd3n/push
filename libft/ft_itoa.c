/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 21:40:04 by abbelhac          #+#    #+#             */
/*   Updated: 2021/05/28 21:43:49 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*to_ascii(char *str, long nb, int len)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
		i = 1;
		while (len > i)
		{
			str[len - i] = (nb % 10) + '0';
			nb /= 10;
			i++;
		}
	}
	else
	{
		while (len > i)
		{
			nb /= 10;
			i++;
		}
	}
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_intlen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (to_ascii(str, nb, len));
}
