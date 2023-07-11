/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:35:20 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/26 16:35:34 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_2(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		str[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		str[j++] = s2[i];
		i++;
	}
	str[j] = 0;
	if (s1)
		free(s1);
	return (str);
}
