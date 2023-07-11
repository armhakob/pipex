/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:25:30 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/22 11:25:30 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	int		i;
	char	*s;
	char	*d;

	if (!str1 && !str2)
		return (0);
	s = (char *)str2;
	d = (char *)str1;
	i = 0;
	if (str1 > str2)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
		while (n--)
			*(d++) = *(s++);
	return (str1);
}
