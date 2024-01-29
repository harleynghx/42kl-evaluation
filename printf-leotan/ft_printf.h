/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:54:49 by leotan            #+#    #+#             */
/*   Updated: 2024/01/18 18:51:49 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_conversion(char sign, int *count, va_list args);
void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_puthex(unsigned long decimal, int *count, char sign);
void	ft_putnbr(long n, int *count);

#endif
