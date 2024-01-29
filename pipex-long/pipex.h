/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 00:13:05 by long              #+#    #+#             */
/*   Updated: 2023/12/30 06:43:39 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include "get_next_line.h"

typedef struct s_pipe
{
	int		ac;
	char	**envp;
	int		**pipefd;
	int		fd1;
	int		fd2;
	char	***cmd;
	char	**cmd_dir;
	int		heredoc;
	char	*input;
}	t_pipe;

char	**ft_split(char const *s, char set);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

// fork_utils
void	dupnclosepipe(int index, t_pipe **a, int i, int fd);
void	closepipe(int index, t_pipe **a);
void	heredocprocess(t_pipe **a);
void	setfd(int m, t_pipe **a);
void	forkprocess(t_pipe **a, char **envp);

// free_utils
void	initheredoc(t_pipe **a, char **av);
void	failedexit(char *str);
void	freepipe(t_pipe **a);
void	freencloseall(t_pipe **a);

// init_utils
char	**initenvp(char **envp);
void	initpipefd(t_pipe **a);
void	initfilefd(t_pipe **a, char **av);
void	prepcmd(t_pipe **a, char **av, int m);
void	initallvar(t_pipe **a, int ac, char **av, char **envp);

// void	opentmpfile(int m, t_pipe **a)
// {
// 	if (m == 3 && (*a)->heredoc == 1)
// 	{
// 		(*a)->fd1 = open("sample.txt", O_RDONLY);
// 		if ((*a)->fd1 == -1)
// 			failedexit("Temp file open failed\n");
// 		unlink("sample.txt");
// 	}
// }

// if ((*a)->heredoc)
// 	close((*a)->fd[0]);
// if ((*a)->heredoc)
// 	close((*a)->fd[1]);

#endif
