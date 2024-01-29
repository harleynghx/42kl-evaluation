/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: long <long@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 23:28:10 by long              #+#    #+#             */
/*   Updated: 2023/12/30 06:49:00 by long             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_pipe	*a;

	if (ac == 1)
		failedexit("No paramters provided error\n");
	a = (t_pipe *) malloc(sizeof(t_pipe));
	if (!a)
		failedexit("Malloc for t_pipe failed.\n");
	initallvar(&a, ac, av, envp);
	if (a->heredoc)
		initheredoc(&a, av);
	forkprocess(&a, envp);
	wait(NULL);
	freencloseall(&a);
	free(a);
	return (0);
}
