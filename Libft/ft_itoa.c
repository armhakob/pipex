/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:23:49 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/23 16:08:29 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (len + 1);
	if (num < 0)
	{
		len++;
		num *= -1;
	}
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (!string)
		return (NULL);
	if (n < 0)
	{
		string[0] = '-';
		n = -n;
	}
	if (n == 0)
		string[0] = '0';
	string[len] = '\0';
	while (n != 0)
	{
		string[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (string);
}
