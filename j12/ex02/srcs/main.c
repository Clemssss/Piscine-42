/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 13:34:49 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/25 19:32:17 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft_tail.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(2, str, ft_strlen(str));
}

void	aff_char(char *str, int nb_car)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] && i < (ft_strlen(str) - nb_car))
		i++;
	j = 0;
	while (str[i] && j < nb_car)
	{
		ft_putchar(str[i]);
		i++;
		j++;
	}
}

int		main(int ac, char **av)
{
	int		nb_car;
	char	*buf;
	int		fd;

	(void)ac;
	nb_car = ft_atoi(av[2]);
	if ((buf = malloc(sizeof(char) * (25000))) == NULL)
		return (-1);
	if (!av[4])
	{
		if ((fd = open(av[3], O_RDONLY)) == -1)
		{
			ft_putstr("ft_tail: ");
			ft_putstr(av[3]);
			ft_putstr(": No such file or directory\n");
			return (-1);
		}
		if (read(fd, buf, 25000) == -1)
			return (-1);
		aff_char(buf, nb_car);
	}
	else
		follow(nb_car, av);
	free(buf);
	return (0);
}
