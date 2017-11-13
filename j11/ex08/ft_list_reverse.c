/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 13:44:17 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/18 16:01:24 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp = *begin_list;
	tmp2 = NULL;
	while (tmp)
	{
		tmp3 = tmp;
		tmp = tmp->next;
		tmp3->next = tmp2;
		tmp2 = tmp3;
	}
	*begin_list = tmp2;
}
