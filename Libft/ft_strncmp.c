/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:29:19 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/22 11:29:19 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (str1[i] && str1[i] == str2[i])
		{
			while (str1[i] && str1[i] == str2[i] && i < n)
				i++;
		}
		else
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
	}
	return (0);
}
