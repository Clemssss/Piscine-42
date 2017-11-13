/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 21:26:01 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/23 23:03:34 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "eval_expr.h"

t_ptr_tab g_tab[] =
{
	{3000000000, ft_sub},
	{3000000001, ft_add},
	{3000000002, ft_div},
	{3000000003, ft_mul},
	{3000000004, ft_mod},
};

long	*adjust(long *tab, long res, int i)
{
	long	*buf;
	int		x;
	int		j;
	int		taille;

	j = 0;
	taille = 0;
	x = 0;
	while (tab[taille] != 3000000005)
		taille++;
	buf = malloc(sizeof(buf) * (taille + 1));
	x = 0;
	while (x < taille)
	{
		if (x == i - 2)
		{
			buf[j++] = res;
			x += 3;
		}
		buf[j++] = tab[x++];
	}
	buf[j] = 3000000005;
	return (buf);
}

long	*set_calc(long *tab, int i)
{
	long	val1;
	long	val2;
	long	res;
	int		x;

	val2 = 0;
	val1 = tab[i - 1];
	val2 = tab[i - 2];
	x = 0;
	while (x < 5)
	{
		if (tab[i] == g_tab[x].opp)
			res = g_tab[x].f(val2, val1);
		x++;
	}
	tab = adjust(tab, res, i);
	return (tab);
}

long	resolve(long *tab)
{
	int		i;

	i = 0;
	while (tab[i] != 3000000005)
	{
		if (tab[i] >= 3000000000 && tab[i] <= 3000000004)
		{
			tab = set_calc(tab, i);
			i = 0;
		}
		else
			i++;
	}
	return (tab[0]);
}
