/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:29:12 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/22 11:29:14 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s || !f)
		return (0);
	res = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < (ft_strlen((char *)s)))
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
