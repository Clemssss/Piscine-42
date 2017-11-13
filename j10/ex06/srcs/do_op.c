/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:17:57 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/17 10:02:03 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_ptr_tab	g_tab[] =
{
	{"-", sub},
	{"+", add},
	{"*", mul},
	{"/", div},
	{"%", mod},
};

int		check_av(char **av)
{
	if ((ft_strcmp(av[2], "-") != 0)
			&& (ft_strcmp(av[2], "+") != 0)
			&& (ft_strcmp(av[2], "/") != 0)
			&& (ft_strcmp(av[2], "*") != 0)
			&& (ft_strcmp(av[2], "%") != 0))
		return (-1);
	return (0);
}

int		loop_tab_ptr(char **av, int val1, int val2)
{
	int		i;

	i = 0;
	while (g_tab[i].operateur)
	{
		if ((ft_strcmp(av[2], "/") == 0) && val2 == 0)
		{
			ft_putstr("Stop : division by zero\n");
			return (0);
		}
		else if ((ft_strcmp(av[2], "%") == 0) && val2 == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return (0);
		}
		else if (ft_strcmp(av[2], g_tab[i].operateur) == 0)
			ft_putnbr(g_tab[i].f(val1, val2));
		i++;
	}
	ft_putchar('\n');
	return (0);
}

int		main(int ac, char **av)
{
	int		val1;
	int		val2;

	if (ac != 4)
		return (-1);
	if (check_av(av) == -1)
	{
		ft_putnbr(0);
		ft_putchar('\n');
		return (0);
	}
	val1 = ft_atoi(av[1]);
	val2 = ft_atoi(av[3]);
	loop_tab_ptr(av, val1, val2);
	return (0);
}
