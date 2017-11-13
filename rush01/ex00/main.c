/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 09:41:54 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/16 18:24:00 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"
#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_nb_solution(char **av)
{
	int		i;
	int		j;
	int		len;

	i = 1;
	len = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= '1' && av[i][j] <= '9')
				len++;
			j++;
		}
		i++;
	}
	return (len);
}

int		check_char(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '.' && (str[i] < '1' || str[i] > '9'))
			return (-1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int			i;

	if (ac != 10 || check_nb_solution(av) < 17)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) != 9 || check_char(av[i]) == -1)
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	if (ft_sudoku(av) == -1)
		return (-1);
	return (0);
}
