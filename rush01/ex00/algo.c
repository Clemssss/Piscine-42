/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 10:32:07 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/16 18:05:10 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		algo(char *av, char *tab, int pos)
{
	char c;

	c = '1';
	if (pos == 81)
		return (1);
	while (c <= '9')
	{
		if (check_av(av, pos))
		{
			if (algo(av, tab, pos + 1))
				return (1);
			return (0);
		}
		else if (ft_check(tab, c, pos))
		{
			tab[pos] = c;
			if (algo(av, tab, pos + 1))
				return (1);
		}
		c = c + 1;
	}
	tab[pos] = '0';
	return (0);
}
