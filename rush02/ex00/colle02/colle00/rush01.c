/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 18:02:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/23 11:30:50 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "colle02.h"

char	*stock_lines_01(t_par par, int a, int x, int y)
{
	if ((par.i == 1 && par.j > 1 && par.j < x)
			|| (par.i > 1 && par.i < y && par.j == 1)
			|| (par.i > 1 && par.i < y && par.j == x)
			|| (par.i == y && par.j > 1 && par.j < x))
		par.buf[a] = '*';
	else if ((par.i == 1 && par.j == 1)
			|| (y != 1 && x != 1 && par.i == y && par.j == x))
		par.buf[a] = '/';
	else if ((par.i == 1 && par.j == x) | (par.i == y && par.j == 1))
		par.buf[a] = '\\';
	else
		par.buf[a] = ' ';
	return (par.buf);
}

char	*rush01(int x, int y)
{
	t_par	par;
	int		a;

	if ((par.buf = malloc(sizeof(t_par) * (x * y + 1))) == NULL)
		return (NULL);
	a = 0;
	par.i = 1;
	while (par.i <= y)
	{
		par.j = 1;
		while (par.j <= x)
		{
			par.buf = stock_lines_01(par, a, x, y);
			a++;
			par.j = par.j + 1;
		}
		par.buf[a++] = '\n';
		par.i = par.i + 1;
	}
	par.buf[a] = '\0';
	return (par.buf);
}
