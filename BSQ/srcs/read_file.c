/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 18:01:22 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/01 19:31:04 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include "bsq.h"

int		sck(t_chars *chars, char *buf)
{
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	i--;
	chars->full = buf[i--];
	chars->obstacle = buf[i--];
	chars->empty = buf[i];
	if (chars->full == chars->obstacle || chars->full == chars->empty
			|| chars->obstacle == chars->full
			|| chars->obstacle == chars->empty
			|| chars->empty == chars->full
			|| chars->empty == chars->obstacle)
		return (-1);
	return (0);
}

int		check(t_chars *chars, char *buf, int i, int j)
{
	char	*str;

	if ((str = malloc(sizeof(char) * 10)) == NULL)
		return (-1);
	while (buf[i] && buf[i] >= '0' && buf[i] <= '9')
		str[j++] = buf[i++];
	str[j] = '\0';
	chars->nbr = ft_atoi(str);
	while (buf[i] && buf[i] != '\n')
		i++;
	i++;
	if (buf[i] == '\0')
		return (-1);
	while (buf[i])
	{
		if ((buf[i] == '\n' && buf[i + 1] && buf[i + 1] == '\n')
				|| (buf[i] != '\n' && buf[i] != chars->obstacle
					&& buf[i] != chars->empty))
			return (-1);
		i++;
	}
	if (buf[i - 1] != '\n')
		return (-1);
	return (0);
}

int		read_fichier(int ac, char **av, int i)
{
	int		fd;
	char	*buf;
	int		**tab;
	t_chars	chars;

	while (av[i])
	{
		if (((fd = open(av[i], O_RDONLY)) == -1)
				|| ((buf = malloc(sizeof(char) * 100000000)) == NULL)
				|| (read(fd, buf, 100000000) == -1)
				|| ((buf[0] < '0' || buf[0] > '9') || sck(&chars, buf) == -1)
				|| (check(&chars, buf, 0, 0) == -1)
				|| ((tab = ft_split_whitespaces(buf, &chars)) == NULL))
			write(2, "map error\n", 10);
		else
		{
			algo(tab, chars, buf);
			free(buf);
			free(tab);
		}
		if (ac > 2 && i < ac - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}

int		read_standard(void)
{
	char	*buf;
	int		**tab;
	t_chars	chars;

	if (((buf = malloc(sizeof(char) * 100000000)) == NULL)
			|| (read(0, buf, 100000000) == -1)
			|| ((buf[0] < '0' || buf[0] > '9') || sck(&chars, buf) == -1)
			|| (check(&chars, buf, 0, 0) == -1)
			|| ((tab = ft_split_whitespaces(buf, &chars)) == NULL))
	{
		write(2, "map error\n", 10);
		return (-1);
	}
	algo(tab, chars, buf);
	free(buf);
	free(tab);
	return (0);
}

int		read_file(int ac, char **av)
{
	if (av[1])
		read_fichier(ac, av, 1);
	else
		read_standard();
	return (0);
}
