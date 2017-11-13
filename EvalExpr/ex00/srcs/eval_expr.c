/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:25:52 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/23 23:18:24 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "eval_expr.h"

char	*ft_strdup(char *src, char *add)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if (add == NULL)
		return (src);
	while (src[i])
		i++;
	while (add[j])
		j++;
	if ((dest = malloc(sizeof(dest) * (i + j + 2))) == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (src[i])
		dest[j++] = src[i++];
	i = 0;
	while (add[i])
		dest[j++] = add[i++];
	dest[j] = '\0';
	return (dest);
}

char	*trans_char_str(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	check(char **tab, char *str, int i, t_operator **op)
{
	char		*buf;

	if (str[i] >= '0' && str[i] <= '9')
		*tab = ft_strdup(*tab, trans_char_str(str[i]));
	else if (str[i] == '+' || str[i] == '-'
			|| str[i] == '*' || str[i] == '/' || str[i] == '%')
	{
		*tab = ft_strdup(*tab, trans_char_str(' '));
		if ((buf = check_op(str[i], op)))
			*tab = ft_strdup(*tab, buf);
	}
	else if (str[i] == '(')
	{
		*tab = ft_strdup(*tab, trans_char_str(' '));
		ft_list_push_front(op, str[i]);
	}
	else if (str[i] == ')')
	{
		*tab = ft_strdup(*tab, trans_char_str(' '));
		*tab = ft_strdup(*tab, destack_op(op, 'N'));
	}
}

int		eval_expr(char *str)
{
	int			i;
	t_operator	*op;
	char		*tab;

	i = 0;
	op = NULL;
	tab = malloc(sizeof(char) * 2);
	tab[0] = '\0';
	while (str[i] != '\0')
	{
		check(&tab, str, i, &op);
		i++;
	}
	tab = ft_strdup(tab, trans_char_str(' '));
	if (op)
		tab = ft_strdup(tab, destack_fin(op));
	return (result(tab));
}
