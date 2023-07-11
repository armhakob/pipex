/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:27:37 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/22 11:27:37 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	i;

	i = (char)c;
	while (*str != '\0' && i != *str)
		str++;
	if (i == *str)
		return ((char *)str);
	return (0);
}
