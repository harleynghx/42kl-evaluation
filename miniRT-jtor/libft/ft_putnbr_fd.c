/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chenlee <chenlee@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 23:19:29 by chenlee           #+#    #+#             */
/*   Updated: 2022/05/04 23:19:29 by chenlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n *= -1;
			ft_putnbr_fd(n, fd);
		}
		else if (n > 0)
		{
			if (n >= 10)
				ft_putnbr_fd((n / 10), fd);
			c = (n % 10) + '0';
			write (fd, &c, 1);
		}
		else if (n == 0)
			write (fd, "0", 1);
	}
}
