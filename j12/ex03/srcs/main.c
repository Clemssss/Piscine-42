/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 16:42:22 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/21 16:52:03 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_hexdump.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		size_tab(char *buf)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (buf[i])
	{
		if (i > 1 && i % 16 == 0)
			len++;
		i++;
	}
	return (len);
}

char	**stock_tab(char **tab, char *buf)
{
	int		i;
	int		j;
	int		x;
	int		s;

	x = 0;
	i = 0;
	if ((tab = malloc(sizeof(char*) * (size_tab(buf) + 2))) == NULL)
		return (NULL);
	s = 0;
	while (buf[x])
	{
		if ((tab[i] = malloc(sizeof(char) * 16 + 1)) == NULL)
			return (NULL);
		j = 0;
		s = x;
		while (buf[x] && x < (s + 16))
		{
			tab[i][j] = buf[x];
			j++;
			x++;
		}
		tab[i][j] = '\0';
		tab[i + 1] = NULL;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	print_octets_hexa(char *str, int j, int x)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof(char) * 20);
	if (j != 0)
	{
		tmp = ft_convert_base(j, "0123456789abcdef");
		while (i < 8 - ft_strlen(tmp))
		{
			ft_putchar('0');
			i++;
		}
		ft_putstr(tmp);
	}
	else
		ft_putstr("00000000");
	if (x == 1)
		return ;
	ft_putstr("  ");
	free(tmp);
	tmp = malloc(sizeof(char) * 20);
	i = 0;
	while (str[i])
	{
		tmp = ft_convert_base(str[i], "0123456789abcdef");
		if (ft_strlen(tmp) == 1)
			ft_putchar('0');
		ft_putstr(tmp);
		if (i == 7)
			ft_putchar(' ');
		ft_putchar(' ');
		i++;
	}
}

char	*change_tab(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32)
			str[i] = '.';
		i++;
	}
	return (str);
}

void	print_space(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 16)
		return ;
}

void	print_tab(char **tab, char **av)
{
	int		i;
	int		c;
	int		j;
	int		s;

	i = 0;
	j = 0;
	s = 0;
	while (tab[i])
	{
		if (c == 1)
			ft_putstr("*\n");
		c = 0;
		if (tab[i + 1])
		{
			while (ft_strcmp(tab[i], tab[i + 1]) == 0)
			{
				i++;
				s += 16;
				j += 16;
				c = 1;
			}
		}
		if (i == 0)
			print_octets_hexa(tab[i], 0, 0);
		else
			print_octets_hexa(tab[i], j - s + 16, 0);
		s = 16;
		print_space(tab[i]);
		if (ft_strcmp(av[1], "-C") == 0)
		{
			ft_putchar('|');
			tab[i] = change_tab(tab[i]);
			ft_putstr(tab[i]);
			ft_putchar('|');
		}
		ft_putchar('\n');
		i++;
		j += 16;
	}
	print_octets_hexa(tab[i - 1], (j - 16) - s + 16 + ft_strlen(tab[i - 1]), 1);
}

int		ft_hexdump(char *buf, char **av)
{
	char	**tab;

	tab = NULL;
	if ((tab = stock_tab(tab, buf)) == NULL)
		return (-1);
	print_tab(tab, av);
	ft_putchar('\n');
	return (0);
}

int		main(int ac, char **av)
{
	char	*buf;
	int		fd;

	(void)ac;
	if ((buf = malloc(sizeof(char) * 25000)) == NULL)
		return (-1);
	if (ft_strcmp(av[1], "-C") == 0)
	{
		if ((fd = open(av[2], O_RDONLY)) == -1)
			return (-1);
		if (read(fd, buf, 25000) == -1)
			return (-1);
	}
	else
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (-1);
		if (read(fd, buf, 25000) == -1)
			return (-1);
	}
	if (ft_hexdump(buf, av) == -1)
		return (-1);
	return (0);
}
