/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 18:14:59 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/20 09:16:48 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;

	tmp = NULL;
	while (*begin_list)
	{
		while (cmp((*begin_list)->data, data_ref) == 0)
		{
			free(*begin_list);
			if (tmp)
				tmp->next = (*begin_list)->next;
			else
				(*begin_list) = (*begin_list)->next;
			(*begin_list) = (*begin_list)->next;
		}
		tmp = *begin_list;
		(*begin_list) = (*begin_list)->next;
	}
}
