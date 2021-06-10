/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:52:38 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/10 19:00:52 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char *s2)
{
	size_t	s1len;
	size_t	s2i;

	s1len = ft_strlen(s1);
	s2i = 0;
	while (s2 && s2[s2i] != '\0')
	{
		s1[s1len] = s2[s2i];
		s1len++;
		s2i++;
	}
	s1[s1len] = '\0';
	return (s1);
}
