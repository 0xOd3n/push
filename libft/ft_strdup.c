/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 01:25:20 by abbelhac          #+#    #+#             */
/*   Updated: 2019/11/17 02:18:55 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int			i;
	char		*mpointer;

	i = 0;
	mpointer = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!mpointer)
		return (0);
	while (s1[i] != '\0')
	{
		mpointer[i] = s1[i];
		i++;
	}
	mpointer[i] = '\0';
	return (mpointer);
}
