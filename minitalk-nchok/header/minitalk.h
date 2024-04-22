/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:55:08 by nchok             #+#    #+#             */
/*   Updated: 2024/04/17 01:06:07 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

/* supplementary functions */
void	print_char_fd(char c, int fd);
void	print_number(int num);
int		ft_atoi(char *str);

/* from client */
void	send(int pid, char *str);

/* from server */
void	process(int num);
void	control(int signal);

#endif
