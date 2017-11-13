/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 12:11:53 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/12 21:55:11 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		nb_lines(char *str, char *charset)
{
	int		len;
	int		i;
	int		j;

	len = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == str[i])
				len++;
			j++;
		}
		i++;
	}
	return (len);
}

int		nb_car(char *str, char *charset, int x)
{
	int		len;
	int		i;

	len = 0;
	while (str[x])
	{
		i = 0;
		while (charset[i])
		{
			if (charset[i] == str[x])
				return (len);
			else
				len++;
			i++;
		}
		x++;
	}
	return (len);
}

int		check_char(char *str, char *charset, int x)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (str[x] == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		x;

	i = 0;
	x = 0;
	tab = malloc(sizeof(char*) * (nb_lines(str, charset) + 2));
	while (str[x])
	{
		if (check_char(str, charset, x) == 0)
		{
			tab[i] = malloc(sizeof(char) * (nb_car(str, charset, x) + 2));
			j = 0;
			while (str[x] && check_char(str, charset, x) == 0)
				tab[i][j++] = str[x++];
			tab[i][j] = '\0';
			if (i != nb_lines(str, charset) + 1)
				i++;
		}
		else
			x++;
	}
	tab[i] = NULL;
	return (tab);
}
