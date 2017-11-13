/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 15:07:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/13 11:16:59 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

int						ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char					*ft_strdup(char *str)
{
	char	*tmp;
	int		i;

	if ((tmp = malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

struct	s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par	*s;

	i = 0;
	s = (t_stock_par*)malloc(sizeof(*s) * (ac + 1));
	while (i < ac)
	{
		s[i].size_param = ft_strlen(av[i]);
		s[i].str = av[i];
		s[i].copy = ft_strdup(av[i]);
		s[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	s[i].str = NULL;
	return (s);
}
