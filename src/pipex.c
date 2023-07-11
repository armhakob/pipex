/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:24:07 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/02 14:37:19 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**pipe_fds(t_pipex data)
{
	int	i;
	int	**fds;

	i = -1;
	fds = malloc(sizeof(int **) * (data.argc - 4));
	if (!fds)
		error();
	while (++i < data.argc - 4)
	{
		fds[i] = malloc(sizeof(int) * 2);
		if (!fds)
			error();
		if (pipe(fds[i]) == -1)
			ft_err_pipe(fds, i);
	}
	return (fds);
}

static void	child_func(t_pipex data, int **fds, int i)
{
	if (i == 2)
	{
		if (dup2(data.fd1, STDIN_FILENO) == -1)
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
	close(data.fd1);
	close(data.fd2);
	free_malloc(data.path);
}

static void	himnakan(t_pipex data, int **fds, int i)
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
		child_func(data, fds, i);
		execve(*cmd, cmd, data.env);
		error();
	}
	free_malloc(cmd);
}

void	pipex(t_pipex data)
{
	int	i;
	int	**fds;

	fds = pipe_fds(data);
	i = 1;
	while (++i < data.argc - 1)
		himnakan(data, fds, i);
	close_fds(data, fds);
	close(data.fd1);
	close(data.fd2);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	data;

	if (argc < 5)
		return (0);
	data.argc = argc;
	data.argv = argv;
	data.env = env;
	data.path = ft_split(find_path(env), ':');
	if (argc > 5 && !ft_strcmp(argv[1], "here_doc"))
	{
		data.fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		here_doc(data);
	}
	else
	{
		data.fd1 = open(argv[1], O_RDONLY);
		data.fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		pipex(data);
	}
	while (wait(NULL) != -1)
		;
	free_malloc(data.path);
	return (0);
}
