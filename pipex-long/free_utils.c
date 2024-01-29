/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:27:49 by long              #+#    #+#             */
/*   Updated: 2024/01/26 02:43:55 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initheredoc(t_pipe **a, char **av)
{
	char	*str;
	char	*limiter;
	char	*buffer;
	char	*tmp;

	write(1, "heredoc> ", 9);
	str = get_next_line(0);
	limiter = ft_strjoin(av[2], "\n");
	buffer = ft_strdup("");
	while (ft_strcmp(str, limiter) && str)
	{
		tmp = ft_strjoin(buffer, str);
		free(str);
		free(buffer);
		buffer = ft_strdup(tmp);
		free(tmp);
		write(1, "heredoc> ", 9);
		str = get_next_line(0);
	}
	free(str);
	free(limiter);
	(*a)->input = buffer;
}

void	failedexit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	freepipe(t_pipe **a)
{
	free((*a)->envp);
	free((*a)->cmd_dir);
	free((*a)->cmd);
	free((*a)->pipefd);
	if ((*a)->heredoc)
		free((*a)->input);
}

void	freencloseall(t_pipe **a)
{
	int	i;
	int	j;

	i = -1;
	while ((*a)->envp[++i])
		free((*a)->envp[i]);
	i = -1;
	while (++i < (*a)->ac - 3 - (*a)->heredoc)
		free((*a)->cmd_dir[i]);
	while (--i >= 0)
	{
		j = -1;
		while ((*a)->cmd[i][++j])
			free((*a)->cmd[i][j]);
		free((*a)->cmd[i]);
	}
	while (++i < (*a)->ac - 4 - (*a)->heredoc)
	{
		close((*a)->pipefd[i][0]);
		close((*a)->pipefd[i][1]);
		free((*a)->pipefd[i]);
	}
	close((*a)->fd1);
	close((*a)->fd2);
	freepipe(a);
}
