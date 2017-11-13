/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:53:11 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/23 23:37:38 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"
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

char	**split_whitespaces(char *str)
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

void	remplir(char **tab, long **tab2, int i)
{
	if (tab[i][0] == '-')
		tab2[0][i] = 3000000000;
	else if (tab[i][0] == '+')
		tab2[0][i] = 3000000001;
	else if (tab[i][0] == '/')
		tab2[0][i] = 3000000002;
	else if (tab[i][0] == '*')
		tab2[0][i] = 3000000003;
	else if (tab[i][0] == '%')
		tab2[0][i] = 3000000004;
}

int		result(char *str)
{
	int		i;
	char	**tab;
	long	*tab2;
	long	resultat;

	tab = split_whitespaces(str);
	tab2 = malloc(sizeof(long) * (nb_lines(str) + 2));
	i = 0;
	while (tab[i])
	{
		if (tab[i][0] >= '0' && tab[i][0] <= '9')
			tab2[i] = ft_atoi(tab[i]);
		else
		{
			remplir(tab, &tab2, i);
		}
		i++;
	}
	tab2[i] = 3000000005;
	resultat = resolve(tab2);
	return (resultat);
}
