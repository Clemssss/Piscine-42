/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 18:57:14 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/25 19:46:39 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft_tail.h"

void	error_message(char *str)
{
	ft_putstr("ft_tail: ");
	ft_putstr(str);
	ft_putstr(": No such file or directory\n");
}

void	aff_str(char *str)
{
	write(1, "==> ", 4);
	write(1, str, ft_strlen(str));
	write(1, " <==\n", 5);
}

int		follow(int nb_car, char **av)
{
	int		i;
	int		fd;
	char	*buf;

	i = 3;
	while (av[i])
	{
		buf = malloc(sizeof(char) * 32000);
		if (((fd = open(av[i], O_RDONLY)) == -1)
				|| (read(fd, buf, 32000) == -1))
			error_message(av[i]);
		else
		{
			aff_str(av[i]);
			aff_char(buf, nb_car);
			if (av[i + 1] && open(av[i + 1], O_RDONLY) != -1)
				ft_putchar('\n');
		}
		fd = 0;
		i++;
	}
	return (0);
}
