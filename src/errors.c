/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:23:46 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/02 14:33:51 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error🤧");
	exit(1);
}

void	ft_error(t_pipex data, int **fds)
{
	perror("Error🤧");
	close_fds(data, fds);
	exit(1);
}

void	ft_err_pipe(int **fds, int i)
{
	int	j;

	j = -1;
	while (++j < i)
	{
		close(fds[j][0]);
		close(fds[j][1]);
		free(fds[j]);
	}
	free(fds[j]);
	free(fds);
}
