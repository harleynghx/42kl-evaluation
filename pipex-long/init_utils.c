/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 22:44:19 by long              #+#    #+#             */
/*   Updated: 2023/12/30 06:48:22 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**initenvp(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
	}
	return (0);
}

void	initpipefd(t_pipe **a)
{
	int		totalpipefd;

	totalpipefd = (*a)->ac - 4 - (*a)->heredoc;
	(*a)->pipefd = (int **)malloc(sizeof(int *) * totalpipefd);
	if (!(*a)->pipefd)
		failedexit("Malloc for pipefd failed\n");
	while (--totalpipefd >= 0)
	{
		(*a)->pipefd[totalpipefd] = (int *)malloc(sizeof(int) * 2);
		if (!(*a)->pipefd[totalpipefd])
			failedexit("Malloc for pipefd[totalpipefd] failed\n");
		if (pipe((*a)->pipefd[totalpipefd]) == -1)
			failedexit("Pipe error\n");
	}
}

void	initfilefd(t_pipe **a, char **av)
{
	if (!(*a)->heredoc)
		(*a)->fd1 = open(av[1], O_RDONLY);
	else
		(*a)->fd1 = open("temp.h", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if ((*a)->fd1 == -1)
		failedexit("Input file error");
	if ((*a)->heredoc)
		(*a)->fd2 = open(av[(*a)->ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0666);
	else
		(*a)->fd2 = open(av[(*a)->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if ((*a)->fd2 == -1)
		failedexit("Output file error");
}

void	prepcmd(t_pipe **a, char **av, int m)
{
	int		i;
	int		idx;
	char	*cmd_path;

	idx = m - 2 - (*a)->heredoc;
	(*a)->cmd[idx] = ft_split(av[m], ' ');
	if (!(access((*a)->cmd[idx][0], X_OK)))
		(*a)->cmd_dir[idx] = ft_strdup((*a)->cmd[idx][0]);
	else
	{
		cmd_path = ft_strjoin("/", (*a)->cmd[idx][0]);
		i = -1;
		while ((*a)->envp[++i])
		{
			(*a)->cmd_dir[idx] = ft_strjoin((*a)->envp[i], cmd_path);
			if (!(access((*a)->cmd_dir[idx], X_OK))
				|| (*a)->envp[i + 1] == NULL)
				break ;
			free((*a)->cmd_dir[idx]);
		}
		free(cmd_path);
	}
}

void	initallvar(t_pipe **a, int ac, char **av, char **envp)
{
	int	m;

	(*a)->heredoc = 0;
	if (ft_strcmp("here_doc", av[1]) == 0)
		(*a)->heredoc = 1;
	if (ac < 5 + (*a)->heredoc)
		failedexit("Insufficient input error");
	(*a)->ac = ac;
	(*a)->envp = initenvp(envp);
	initpipefd(a);
	initfilefd(a, av);
	(*a)->cmd = (char ***)malloc(sizeof(char **) * (ac - 3 - (*a)->heredoc));
	if (!(*a)->cmd)
		failedexit("Malloc for cmd failed\n");
	(*a)->cmd_dir = (char **)malloc(sizeof(char *) * (ac - 3 - (*a)->heredoc));
	if (!(*a)->cmd_dir)
		failedexit("Malloc for cmd_str failed\n");
	m = 1 + (*a)->heredoc;
	while (++m < ac - 1)
		prepcmd(a, av, m);
}
