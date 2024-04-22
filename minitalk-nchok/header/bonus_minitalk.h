/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minitalk.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:05:53 by nchok             #+#    #+#             */
/*   Updated: 2024/04/18 14:25:10 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_MINITALK_H
# define BONUS_MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>

/* server */
void	process(int num, siginfo_t *info);
void	control(int signal, siginfo_t *info, void *context);

/* client */
void	send(int pid, char *str);

/* helper */
void	print_char_fd(char c, int fd);
void	print_number(int num);
int		ft_atoi(char *str);

#endif
