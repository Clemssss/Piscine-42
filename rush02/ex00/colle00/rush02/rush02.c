/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:31:39 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/22 11:47:48 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle00.h"

void	particular_x_y(int x, int y, int i, int j)
{
	if (y == 1)
	{
		if (j == 0)
			ft_putchar('A');
		else if (j == x - 1)
			ft_putchar('A');
		else
			ft_putchar('B');
	}
	else if (x == 1)
	{
		if (i == 0)
			ft_putchar('A');
		else if (i == y - 1)
			ft_putchar('C');
	}
}

void	print_line(int x, int y, int i, int j)
{
	if (x == 1 || y == 1)
		particular_x_y(x, y, i, j);
	else
	{
		if ((j == 0 && i == 0) || (j == x - 1 && i == 0))
			ft_putchar('A');
		else if ((j == 0 && i == y - 1) || (i == y - 1 && j == x - 1))
			ft_putchar('C');
		else if (i == 0 || i == y - 1)
			ft_putchar('B');
		else if (j == x - 1 && i > 0 && i < y && x > 1)
			ft_putchar('B');
		else if (j + 1 < x - 1)
			ft_putchar(' ');
	}
}

int		rush(int x, int y)
{
	int		i;
	int		j;

	i = 0;
	if (x <= 0 || y <= 0)
		return (-1);
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			print_line(x, y, i, j);
			j++;
		}
		ft_putchar('\n');
		i++;
		if (i > 0 && i < y - 1)
			ft_putchar('B');
	}
	return (0);
}
