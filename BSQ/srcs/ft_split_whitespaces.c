/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:02:12 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/01 19:32:53 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

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

int		check_nb_char(int i, int j, t_chars *chars)
{
	if (i >= 1)
	{
		if (i > 1)
			if (j != chars->nb_column)
				return (-1);
		chars->nb_column = j;
	}
	return (0);
}

int		**loop(t_stock *s, t_chars *chars, char *str, int *x)
{
	if ((s->tab[s->i] = malloc(sizeof(int) * (nb_car(str, *x) + 2))) == NULL)
		return (NULL);
	s->j = 0;
	while (str[*x] && str[*x] != ' ' && str[*x] != '\n' && str[*x] != '\t')
	{
		if (str[*x] == chars->empty)
			s->tab[s->i][s->j] = 1;
		else
			s->tab[s->i][s->j] = 0;
		*x = *x + 1;
		s->j = s->j + 1;
	}
	if (check_nb_char(s->i, s->j, chars) == -1)
		return (NULL);
	s->tab[s->i][s->j] = '\0';
	if (s->i != nb_lines(str) + 1)
		s->i = s->i + 1;
	return (s->tab);
}

int		**ft_split_whitespaces(char *str, t_chars *chars)
{
	t_stock	s;
	int		x;

	if ((s.tab = malloc(sizeof(int*) * (nb_lines(str) + 2))) == NULL)
		return (NULL);
	x = 0;
	s.i = 0;
	while (str[x])
	{
		if (str[x] != ' ' && str[x] != '\n' && str[x] != '\t')
		{
			if ((s.tab = loop(&s, chars, str, &x)) == NULL)
				return (NULL);
		}
		else
			x++;
	}
	if (chars->nbr != s.i - 1)
		return (NULL);
	chars->nb_lines = s.i;
	s.tab[s.i] = NULL;
	return (s.tab);
}
