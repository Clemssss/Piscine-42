/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:02:12 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/13 10:44:55 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		nb_lines(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			&& (str[i + 1] != ' ' && str[i + 1] != '\t'
				&& str[i + 1] != '\n' && str[i + 1]))
			len++;
		i++;
	}
	return (len);
}

int		nb_car(char *str, int x)
{
	int		len;

	len = 0;
	while (str[x] && str[x] != ' ' && str[x] != '\t' && str[x] != '\n')
	{
		len++;
		x++;
	}
	return (len);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		x;

	tab = malloc(sizeof(char*) * (nb_lines(str) + 2));
	x = 0;
	i = 0;
	while (str[x])
	{
		if (str[x] != ' ' && str[x] != '\n' && str[x] != '\t')
		{
			tab[i] = malloc(sizeof(char) * (nb_car(str, x) + 2));
			j = 0;
			while (str[x] && str[x] != ' ' && str[x] != '\n' && str[x] != '\t')
				tab[i][j++] = str[x++];
			tab[i][j] = '\0';
			if (i != nb_lines(str) + 1)
				i++;
		}
		else
			x++;
	}
	tab[i] = NULL;
	return (tab);
}
