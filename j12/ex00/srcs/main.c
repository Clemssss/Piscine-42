/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 10:56:22 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/19 13:38:52 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "display_file.h"

int		manage_args(int ac)
{
	if (ac == 1)
	{
		write(2, "File name missing.\n", 19);
		return (-1);
	}
	else if (ac > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (-1);
	}
	return (0);
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
	write(1, str, ft_strlen(str));
}

int		main(int ac, char **av)
{
	char	buf[32000];
	int		fd;

	if (manage_args(ac) == -1)
		return (-1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	if ((read(fd, buf, 32000)) == -1)
		return (-1);
	ft_putstr(buf);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
