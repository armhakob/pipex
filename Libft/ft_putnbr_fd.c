/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:27:05 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/22 17:57:34 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
		}
		else
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd((n * -1), fd);
		}
	}
	if (n >= 0)
	{
		if (n > 9)
			ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
}
