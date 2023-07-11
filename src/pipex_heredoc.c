/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:23:54 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/02 14:34:47 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_func_heredoc(t_pipex data, int **fds, int i)
{
	if (i == 2)
	{
		if (dup2(fds[0][0], STDIN_FILENO) == -1)
			ft_error(data, fds);
		if (dup2(fds[i - 2][1], STDOUT_FILENO) == -1)
			ft_error(data, fds);
	}
	else if (i == data.argc - 2)
	{
		if (dup2(fds[i - 3][0], STDIN_FILENO) == -1)
			ft_error(data, fds);
		if (dup2(data.fd2, STDOUT_FILENO) == -1)
			ft_error(data, fds);
	}
	else
	{
		if (dup2(fds[i - 3][0], STDIN_FILENO) == -1)
			ft_error(data, fds);
		if (dup2(fds[i - 2][1], STDOUT_FILENO) == -1)
			ft_error(data, fds);
	}
	close_fds(data, fds);
	close(data.fd2);
	free_malloc(data.path);
}

static void	himnakan_heredoc(t_pipex data, int **fds, int i)
{
	pid_t	id;
	char	**cmd;

	cmd = ft_split(data.argv[i], ' ');
	if (!cmd)
		ft_error(data, fds);
	if (cmd[0] && !ft_strchr(cmd[0], '/'))
		*cmd = find_cmd(data, cmd);
	id = fork();
	if (id == -1)
		ft_error(data, fds);
	if (!id)
	{
		child_func_heredoc(data, fds, i);
		execve(*cmd, cmd, data.env);
		error();
	}
	free_malloc(cmd);
}

void	here_doc(t_pipex data)
{
	int		i;
	int		**fds;
	char	*str;
	char	*lim;

	fds = pipe_fds(data);
	lim = ft_strjoin(data.argv[2], "\n");
	while (1)
	{
		write(1, ">", 1);
		str = get_next_line(0);
		if (!str || !ft_strcmp(lim, str))
			break ;
		ft_putstr_fd(str, data.fd2);
		free(str);
	}
	free(str);
	i = 2;
	while (++i < data.argc - 1)
		himnakan_heredoc(data, fds, i);
	free(lim);
	close(data.fd2);
	close_fds(data, fds);
}
