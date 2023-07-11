/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 14:30:32 by armhakob          #+#    #+#             */
/*   Updated: 2023/07/02 14:38:59 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_pipex{
	int		argc;
	char	**argv;
	char	**env;
	char	**path;
	int		fd1;
	int		fd2;
}	t_pipex;

void	error(void);
void	ft_error(t_pipex data, int **fds);
void	ft_err_pipe(int **fds, int i);
void	pipex(t_pipex data);
void	free_malloc(char **str);
void	close_fds(t_pipex data, int **fds);
int		**pipe_fds(t_pipex data);
char	*find_path(char **envp);
char	*find_path(char **envp);
char	*find_cmd(t_pipex data, char **cmd);
void	here_doc(t_pipex data);

#endif