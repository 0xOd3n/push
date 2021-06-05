/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbelhac <abbelhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:53:16 by abbelhac          #+#    #+#             */
/*   Updated: 2021/05/28 21:44:45 by abbelhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	pos;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	pos = n;
	if (pos > 9)
	{
		ft_putnbr_fd(pos / 10, fd);
		ft_putnbr_fd(pos % 10, fd);
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', fd);
}
