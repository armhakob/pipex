/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tashaxusta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:41:38 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/11 20:18:16 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_split(ft_strchr(envp[i], '/'), ':'));
		i++;
	}
	return (0);
}

char	*find_cmd(t_pipex data, char **cmd)
{
	char	*str;
	char	*tmp;
	int		i;

	i = -1;
	str = ft_strjoin("/", *cmd);
	while (data.path[++i])
	{
		tmp = ft_strjoin(data.path[i], str);
		if (!access(tmp, X_OK))
		{
			free(*cmd);
			free(str);
			return (tmp);
		}
		free(tmp);
	}
	free(str);
	return (*cmd);
}

void	free_malloc(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

void	close_fds(t_pipex data, int **fds)
{
	int	i;

	i = 0;
	while (i < data.argc - 4)
	{
		close(fds[i][0]);
		close(fds[i][1]);
		free(fds[i]);
		i++;
	}
	free(fds);
}
