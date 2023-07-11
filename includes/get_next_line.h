/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:15:17 by armhakob          #+#    #+#             */
/*   Updated: 2023/05/22 11:56:08 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
char	*ft_join_free(char *buffer, char *buff);
char	*read_file(int fd, char *res);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);
char	*get_next_line(int fd);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);

size_t	gnl_strlen(const char *str);

#endif