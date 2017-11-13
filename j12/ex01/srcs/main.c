/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 12:06:13 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/27 13:58:55 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "ft_cat.h"

void	b_zero(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
		buf[i++] = '\0';
}

void	standard_input(void)
{
	char	buf[25000];

	while (42)
	{
		read(0, buf, 25000);
		ft_putstr(buf);
		b_zero(buf);
	}
}

void	print_error(char *av, char *str)
{
	ft_puterror("cat: ");
	ft_puterror(av);
	ft_puterror(str);
}

int		read_files(char **av)
{
	char	buf[25000];
	int		fd;
	int		i;

	i = 1;
	while (av[i])
	{
		if ((fd = open(av[i], O_RDONLY)) == -1)
			print_error(av[i], ": No such file or directory\n");
		else if (read(fd, buf, 25000) == -1)
			print_error(av[i], ": Is a directory\n");
		else
		{
			ft_putstr(buf);
			b_zero(buf);
		}
		i++;
	}
	close(fd);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		standard_input();
		return (0);
	}
	if (read_files(av) == -1)
		return (-1);
	return (0);
}
