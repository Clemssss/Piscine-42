/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 22:52:46 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/23 23:04:42 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "eval_expr.h"

t_operator	*ft_create_elem(char data)
{
	t_operator	*list;

	list = malloc(sizeof(*list));
	list->data = data;
	list->next = NULL;
	return (list);
}

void		ft_list_push_front(t_operator **begin_list, char data)
{
	t_operator	*tmp;

	tmp = ft_create_elem(data);
	tmp->next = *begin_list;
	*begin_list = tmp;
}
