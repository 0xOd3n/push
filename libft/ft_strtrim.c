/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:11:28 by abbelhac          #+#    #+#             */
/*   Updated: 2021/05/28 21:49:07 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_be_trimed(char c, char *set)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	j;
	int				dstlen;
	char			*strim;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		if (to_be_trimed(s1[i], (char *)set) == 0)
			break ;
		i++;
	}
	j = (ft_strlen(s1));
	while (j-- && j >= i)
	{
		if (to_be_trimed(s1[j], (char *)set) == 0)
			break ;
	}
	dstlen = j - i;
	strim = ft_substr(s1, i, dstlen + 1);
	return (strim);
}
