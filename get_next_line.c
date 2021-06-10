/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:11:41 by abbelhac          #+#    #+#             */
/*   Updated: 2021/06/10 20:08:54 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*fill_line(char *save, char **line)
{
	int			i;
	char		*rest;

	i = 0;
	while (save && save[i] && save[i] != '\n')
		i++;
	*line = ft_strndup(save, i);
	rest = substr(save, i + 1, (ft_strlen(save) - i));
	return (rest);
}

void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

int	get_next_line(int fd, char **line)
{
	int				ret;
	char			*rbuff;
	static char		*save;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	rbuff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!rbuff)
		return (-1);
	ret = 1;
	while (ret > 0 && !ft_strchr(save, '\n'))
	{
		ret = read(fd, rbuff, BUFFER_SIZE);
		rbuff[ret] = '\0';
		save = join(save, rbuff);
	}
	ft_free(&rbuff);
	save = fill_line(save, line);
	if (ret == 0)
		ft_free(&save);
	if (ret > 0)
		return (1);
	return (0);
}
