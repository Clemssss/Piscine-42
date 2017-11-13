/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:14:35 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/08 11:36:36 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	particular_x_y(int x, int y, int i, int j)
{
	if (y == 1)
	{
		if (j == 0)
			ft_putchar('A');
		else if (j == x - 1)
			ft_putchar('C');
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
		if ((j == x - 1 && i == y - 1) || (j == 0 && i == 0))
			ft_putchar('A');
		else if ((j == x - 1 && i == 0) || (i == y - 1 && j == 0))
			ft_putchar('C');
		else if (i == 0 || i == y - 1)
			ft_putchar('B');
		else
			ft_putchar(' ');
		if (j == x - 3 && i > 0 && i < y - 1)
			ft_putchar('B');
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
