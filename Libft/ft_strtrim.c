/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:30:17 by armhakob          #+#    #+#             */
/*   Updated: 2023/01/22 17:58:02 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	str = 0;
	if (s1 && set)
	{
		i = 0;
		start = 0;
		end = ft_strlen(s1);
		while (ft_strchr(set, s1[start]) && start < end)
			start++;
		while (ft_strchr(set, s1[end -1]) && end > start)
			end--;
		str = (char *)malloc(sizeof(*s1) * (end - start + 1));
		if (!str)
			return (0);
		while (start < end)
			str[i++] = s1[start++];
		str[i] = '\0';
	}
	return (str);
}
