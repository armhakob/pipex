/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:27:52 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/22 11:27:52 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*mas;
	int		ca;

	ca = ft_strlen(src);
	mas = (char *)malloc(ca + 1);
	if (!mas)
		return (0);
	mas = ft_strcpy(mas, src);
	return (mas);
}
