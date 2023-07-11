/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:21:54 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/22 11:21:54 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	dst = malloc(count * size);
	if (dst == NULL)
		return (NULL);
	ft_memset((unsigned char *)dst, 0, count * size);
	return (dst);
}
