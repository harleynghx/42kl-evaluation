/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lekai-we <lekai-we@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:36:08 by lekai-we          #+#    #+#             */
/*   Updated: 2024/01/14 19:00:09 by lekai-we         ###   ########.fr       */
/*   Created: 2024/01/14 17:00:41 by lekai-we          #+#    #+#             */
/*   Updated: 2024/01/14 17:08:42 by lekai-we         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	top(void)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	ft_putchar('/');
	while (i < (x - 2))
	{
		ft_putchar ('*');
		i++;
	}
	ft_putchar ('\\');
	ft_putchar ('\n');
}

void	bot(void)
{
	int	l;
	int	x;

	l = 0;
	x = 0;
	ft_putchar ('\\');
	while (l < (x - 2))
	{
		ft_putchar ('*');
		l++;
	}
	ft_putchar('/');
}

void	rush(x, y)
{
	int	j;
	int	k;
	int	x;

	j = 0;
	k = 0;
	x = 0;
	top();
	while (j < (y - 2))
	{
		while (k < x)
		{
			if (k == 0)
			{
				ft_putchar ('*');
			}
			else if (k < (x - 1))
			{
				write (1, " ", 1);
			}
			else if (k == (x - 1))
			{
				ft_putchar ('*');
				ft_putchar ('\n');
			}k++;
		}j++;
	}
	bot();
}  
