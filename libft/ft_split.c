/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 22:49:37 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/18 15:46:42 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countrows(char const *s, char c)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			row++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (row);
}

static int	wordlen(char const *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
		if (s[i] == c)
			return (len);
	}
	return (len);
}

static	int	free_arr(char **arr, int rows)
{
	int	i;

	i = 0;
	if (!arr[rows])
	{
		while (i < rows)
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		rows;
	char	**arr;

	arr = (char **) malloc(sizeof(char *) * (countrows(s, c) + 1));
	if (!s || !arr)
		return (0);
	i = 0;
	rows = 0;
	while (s[i] && rows < countrows(s, c))
	{
		i += next_word(&s[i], c);
		if (s[i])
		{
			arr[rows] = ft_substr(s, i, wordlen(&s[i], c));
			if (free_arr(arr, rows))
				return (0);
			rows++;
		}
		i += next_c(&s[i], c);
	}
	arr[rows] = 0;
	return (arr);
}
