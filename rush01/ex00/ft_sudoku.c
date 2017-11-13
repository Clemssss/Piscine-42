/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 09:54:28 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/16 19:07:21 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_tab(char *tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putchar(tab[i]);
		if (i % 9 != 8)
			ft_putchar(' ');
		if (i % 9 == 8)
			ft_putchar('\n');
		i++;
	}
}

void	call_algo(char *tab)
{
	char	*str;

	str = ft_strdup(tab);
	if (algo(str, tab, 0))
		display_tab(tab);
	else
		write(2, "Error\n", 6);
	free(tab);
}

int		ft_sudoku(char **av)
{
	int		j;
	int		i;
	int		x;
	char	*tab;

	if ((tab = malloc(sizeof(char) * (81 + 1))) == NULL)
		return (-1);
	i = 1;
	x = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '.')
				tab[x++] = '0';
			else
				tab[x++] = av[i][j];
			j++;
		}
		i++;
	}
	tab[x] = '\0';
	call_algo(tab);
	return (0);
}
