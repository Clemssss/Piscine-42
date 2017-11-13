/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 16:40:28 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/18 16:53:20 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*tmp;

	while (begin_list)
	{
		if (cmp(begin_list->data, data_ref) == 0)
		{
			tmp = begin_list;
			return (tmp);
		}
		begin_list = begin_list->next;
	}
	return (NULL);
}
