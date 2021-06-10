/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:11:53 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/10 20:08:44 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*join(char *s1, char const *s2)
{
	char			*dst;
	size_t			lens1;
	size_t			lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	dst = (char *)malloc((lens1 + lens2) + 1);
	if (!dst)
		return (NULL);
	ft_strcpy(dst, (char *)s1);
	ft_strcat(dst, (char *)s2);
	free(s1);
	return (dst);
}

char	*substr(char *s, unsigned int start, size_t len)
{
	char		*dst;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	free(s);
	return (dst);
}
