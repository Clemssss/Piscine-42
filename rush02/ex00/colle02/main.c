/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:18:23 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/23 12:03:00 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include "colle02.h"

t_colle	g_colle[] =
{
	{rush00, colle00},
	{rush01, colle01},
	{rush02, colle02},
	{rush03, colle03},
	{rush04, colle04},
};

int		call_ptr_fct(char *buf, int *s)
{
	int		i;

	i = 0;
	while (i <= 4)
	{
		if (ft_strcmp(buf, g_colle[i].g(nb_car(buf), nb_line(buf))) == 0)
		{
			if (*s > 0)
				ft_putstr(" || ");
			g_colle[i].f(nb_car(buf), nb_line(buf));
			*s = *s + 1;
		}
		i++;
	}
	return (0);
}

int		main(void)
{
	char	*buf;
	int		s;

	if (((buf = read_file()) == NULL)
			|| (ft_strlen(buf) == 0))
	{
		ft_putstr("aucune\n");
		return (-1);
	}
	s = 0;
	call_ptr_fct(buf, &s);
	if (s == 0)
		ft_putstr("aucune");
	ft_putchar('\n');
	return (0);
}
