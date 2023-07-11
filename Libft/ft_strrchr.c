/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:29:39 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/22 11:29:39 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	j;

	j = (char)c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (j == str[i])
			return ((char *)str + i);
		i--;
	}
	return (0);
}
