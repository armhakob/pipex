/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:28:43 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/22 11:28:43 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l;
	size_t	k;

	if (!dst && dstsize == 0)
		return (0);
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	l = ft_strlen(dst);
	k = 0;
	while (src[k] != '\0' && l + 1 < dstsize)
	{
		dst[l] = src[k];
		l++;
		k++;
	}
	dst[l] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[k]));
}
