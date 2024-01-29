/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntham <ntham@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:49:06 by ntham             #+#    #+#             */
/*   Updated: 2024/01/14 15:21:59 by ntham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char A);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (j <= y)
	{
		while (i <= x)
		{
			if ((i == 1 && j == 1) || (i == x && j == y && i != 1 && j != 1))
				ft_putchar('A');
			else if (j != y && j != 1 && i != x && i != 1)
				ft_putchar(' ');
			else if ((i == x && j == 1) || (i == 1 && j == y))
				ft_putchar('C');
			else
				ft_putchar('B');
			i++;
		}
		if ((i == x +1) && i != 1)
			ft_putchar('\n');
		i = 1;
		j++;
	}
}
