/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 14:52:07 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/01 19:30:30 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		**remp_case(int **tab, int i, int j)
{
	int		diag;
	int		top;
	int		left;

	diag = tab[i - 1][j - 1];
	top = tab[i - 1][j];
	left = tab[i][j - 1];
	if (diag <= top && diag <= left)
		tab[i][j] = diag + 1;
	else if (top <= diag && top <= left)
		tab[i][j] = top + 1;
	else if (left <= diag && left <= top)
		tab[i][j] = left + 1;
	return (tab);
}

void	remp_pos(int **tab, t_pos *pos, int i, int j)
{
	pos->pos_x = i;
	pos->pos_y = j;
	pos->car = tab[i][j];
}

int		**demin(int **tab, t_chars chars, t_pos *pos)
{
	int		i;
	int		j;

	i = 2;
	pos->s_x = 1;
	pos->s_y = 0;
	while (i < chars.nb_lines && (j = 1) != -1)
	{
		while (j < chars.nb_column)
		{
			if (tab[i][j] == 1)
			{
				tab = remp_case(tab, i, j);
				if (tab[i][j] > tab[pos->s_x][pos->s_y])
				{
					remp_pos(tab, pos, i, j);
					pos->s_x = i;
					pos->s_y = j;
				}
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int		line_or_col_1(int **tab, t_chars chars)
{
	int		i;
	int		j;
	int		s;

	i = 1;
	s = 0;
	while (i < chars.nb_lines && (j = 0) != -1)
	{
		while (j < chars.nb_column)
		{
			if (tab[i][j] == 0)
				ft_putchar(chars.obstacle);
			else if (tab[i][j] == 1 && s == 0)
			{
				ft_putchar(chars.full);
				s++;
			}
			else
				ft_putchar(chars.empty);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}

void	print_croix(int **tab, t_chars chars, t_pos pos)
{
	int		i;
	int		j;

	i = 1;
	if (pos.pos_x == 1 && pos.pos_y == 0)
	{
		line_or_col_1(tab, chars);
		return ;
	}
	while (i < chars.nb_lines && (j = 0) != -1)
	{
		while (j < chars.nb_column)
		{
			if (tab[i][j] == 0)
				ft_putchar(chars.obstacle);
			else if ((i > (pos.pos_x - pos.car) && i <= pos.pos_x)
					&& (j > (pos.pos_y - pos.car) && j <= pos.pos_y))
				ft_putchar(chars.full);
			else
				ft_putchar(chars.empty);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
