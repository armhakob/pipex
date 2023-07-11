/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:30:33 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/28 13:36:23 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

long	ft_atol(const char *str)
{
	long		num;
	long		sign;
	const char	*s;

	num = 0;
	sign = 1;
	s = str;
	while (ft_iswhitespace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s == '0')
		s++;
	num = atol_num(sign, s);
	return (num);
}

long	atol_num(long sign, const char *s)
{
	long	num;

	num = 0;
	if (ft_strlen(s) > 10)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	while (*s != '\0')
	{
		if (!ft_isdigit(*s))
			break ;
		num *= 10;
		num += (int)(*s - '0');
		s++;
	}
	if ((sign == -1 && num > 2147483648) || (sign == 1 && num > 2147483647))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (sign * num);
}
