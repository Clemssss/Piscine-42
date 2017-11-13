/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 20:18:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/16 18:40:46 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		ft_column(char *tab, char c, int pos)
{
	int		column;
	int		i;

	column = pos % 9;
	i = 0;
	while (i < 9)
	{
		if (tab[column] == c)
			return (0);
		column += 9;
		i += 1;
	}
	return (1);
}

int		ft_row(char *tab, char c, int pos)
{
	int		start;
	int		end;

	start = (pos / 9) * 9;
	end = start + 8;
	while (start <= end)
	{
		if (tab[start] == c)
			return (0);
		start++;
	}
	return (1);
}

int		ft_bloc(char *tab, char c, int pos)
{
	int		ini_column;
	int		ini_row;
	int		ini_bloc;
	int		i;
	int		j;

	ini_column = pos - (pos % 3);
	ini_row = (ini_column / 9) % 3;
	ini_bloc = ini_column - (9 * ini_row);
	i = 0;
	while (i < 3)
	{
		j = ini_bloc;
		while (j < ini_bloc + 3)
		{
			if (tab[j] == c)
				return (0);
			j++;
		}
		ini_bloc += 9;
		i += 1;
	}
	return (1);
}

int		check_av(char *str, int pos)
{
	if (str[pos] == '0')
		return (0);
	return (1);
}

int		ft_check(char *tab, char c, int pos)
{
	if (ft_column(tab, c, pos) && ft_row(tab, c, pos) && ft_bloc(tab, c, pos))
		return (1);
	return (0);
}
