/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remp_list_operator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 15:20:32 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/23 23:31:55 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "eval_expr.h"

t_operand	g_opp[] =
{
	{'+', 1},
	{'-', 1},
	{'/', 2},
	{'*', 2},
	{'%', 2},
};

char		*destack_op(t_operator **op, char c)
{
	char		*str;
	t_operator	*tmp;
	int			i;

	str = malloc(sizeof(char) * 5);
	i = 0;
	while ((*op) && (*op)->data != '(')
	{
		str[i] = (*op)->data;
		tmp = *op;
		i++;
		str[i++] = ' ';
		(*op) = (*op)->next;
		free(tmp);
	}
	if ((*op) && (*op)->data == '(' && c == 'N')
	{
		tmp = *op;
		(*op) = (*op)->next;
		free(tmp);
	}
	str[i] = '\0';
	if (c != 'N')
		ft_list_push_front(op, c);
	return (str);
}

char		*loop_check_op(t_operator **op, char c, char der)
{
	int		val;
	int		j;
	int		i;

	i = 0;
	while (i < 5)
	{
		if (c == g_opp[i].type)
		{
			val = g_opp[i].rank;
			j = 0;
			while (j < 5)
			{
				if (der == g_opp[j].type)
					if (val <= g_opp[j].rank)
						return (destack_op(op, c));
				j++;
			}
		}
		i++;
	}
	ft_list_push_front(op, c);
	return (NULL);
}

char		*check_op(char c, t_operator **op)
{
	char	der;

	if ((*op) != NULL)
		der = (*op)->data;
	else
	{
		ft_list_push_front(op, c);
		return (NULL);
	}
	return (loop_check_op(op, c, der));
}

char		*destack_fin(t_operator *op)
{
	char		*str;
	t_operator	*tmp;
	int			i;

	if ((str = malloc(sizeof(char) * 5)) == NULL)
		return (NULL);
	i = 0;
	while (op)
	{
		str[i] = op->data;
		tmp = op;
		i++;
		str[i++] = ' ';
		op = op->next;
		free(tmp);
	}
	str[i] = '\0';
	return (str);
}
