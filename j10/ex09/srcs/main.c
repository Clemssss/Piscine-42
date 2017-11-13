/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:18:57 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/17 16:16:01 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"
#include "ft_opp.h"

int		parse_ptrtab(char **av, int val1, int val2)
{
	int		i;

	i = 0;
	while (g_opptab[i].opp)
	{
		if (ft_strcmp(av[2], "/") == 0 && val2 == 0)
		{
			ft_putstr("Stop : division by zero\n");
			return (0);
		}
		else if (ft_strcmp(av[2], "%") == 0 && val2 == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return (0);
		}
		else if (ft_strcmp(g_opptab[i].opp, av[2]) == 0)
		{
			ft_putnbr(g_opptab[i].f(val1, val2));
			ft_putchar('\n');
			return (0);
		}
		i++;
	}
	g_opptab[5].f(val1, val2);
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	int		val1;
	int		val2;

	if (ac != 4)
		return (0);
	i = 0;
	val1 = ft_atoi(av[1]);
	val2 = ft_atoi(av[3]);
	parse_ptrtab(av, val1, val2);
	return (0);
}
