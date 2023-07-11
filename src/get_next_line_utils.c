/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:14:52 by armhakob          #+#    #+#             */
/*   Updated: 2023/05/22 11:57:39 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(*s1) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

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

void	ft_bzero(void *s, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		*(char *)(s + k) = 0;
		k++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*dst;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	dst = malloc(count * size);
	if (dst == 0)
		return (0);
	ft_bzero((unsigned char *)dst, count * size);
	return (dst);
}

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len] != '\0')
		len++;
	return (len);
}
