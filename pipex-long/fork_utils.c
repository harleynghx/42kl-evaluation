/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:24:11 by long              #+#    #+#             */
/*   Updated: 2023/12/30 06:23:25 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dupnclosepipe(int index, t_pipe **a, int i, int fd)
{
	if (i != index - 3 - (*a)->heredoc + fd)
		close((*a)->pipefd[i][fd]);
	else
		dup2((*a)->pipefd[i][fd], fd);
}

void	closepipe(int index, t_pipe **a)
{
	int	i;

	i = -1;
	while (++i < (*a)->ac - 4 - (*a)->heredoc)
	{
		if (index == 2 + (*a)->heredoc)
		{
			close((*a)->pipefd[i][0]);
			dupnclosepipe(index, a, i, STDOUT_FILENO);
		}
		else if (index == (*a)->ac - 2)
		{
			close((*a)->pipefd[i][1]);
			dupnclosepipe(index, a, i, STDIN_FILENO);
		}
		else
		{
			dupnclosepipe(index, a, i, STDIN_FILENO);
			dupnclosepipe(index, a, i, STDOUT_FILENO);
		}
	}
}

void	heredocprocess(t_pipe **a)
{
	int	i;

	i = -1;
	while (++i < (*a)->ac - 4 - (*a)->heredoc)
	{
		close((*a)->pipefd[i][0]);
		close((*a)->pipefd[i][1]);
	}
	dup2((*a)->fd1, 1);
	write(1, (*a)->input, ft_strlen((*a)->input));
	close((*a)->fd1);
	exit(EXIT_SUCCESS);
}

void	setfd(int m, t_pipe **a)
{
	if (m == 3 && (*a)->heredoc == 1)
	{
		(*a)->fd1 = open("temp.h", O_RDONLY);
		unlink("temp.h");
		if ((*a)->fd1 == -1)
			failedexit("Temp file open failed");
	}
	if (m == 2 + (*a)->heredoc)
		dup2((*a)->fd1, 0);
	else if (m == (*a)->ac - 2)
		dup2((*a)->fd2, 1);
}

void	forkprocess(t_pipe **a, char **envp)
{
	int	m;
	int	pid;

	m = 1;
	while (++m < (*a)->ac - 1)
	{
		pid = fork();
		if (pid == -1)
			failedexit("Fork error");
		if (pid == 0)
		{
			if (m == 2 && (*a)->heredoc == 1)
				heredocprocess(a);
			closepipe(m, a);
			setfd(m, a);
			if (access((*a)->cmd_dir[m - 2 - (*a)->heredoc], X_OK))
				failedexit("command not found");
			execve((*a)->cmd_dir[m - 2 - (*a)->heredoc],
				(*a)->cmd[m - 2 - (*a)->heredoc], envp);
			failedexit("Execve error");
		}
	}
}
