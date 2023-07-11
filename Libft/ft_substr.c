/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:30:32 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/23 12:12:24 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*src;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	src = (char *)malloc((len + 1) * sizeof(char));
	if (!src)
		return (0);
	count = 0;
	while (count < len)
	{
		src[count] = s[start + count];
		count++;
	}
	src[count] = '\0';
	return (src);
}
