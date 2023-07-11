/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:25:10 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/22 11:25:10 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str1)[i] != ((unsigned char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}
