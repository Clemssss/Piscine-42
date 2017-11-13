/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 09:09:21 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/19 10:05:20 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	swap_list(void **data1, void **data2)
{
	void	*ret;

	ret = *data1;
	*data1 = *data2;
	*data2 = ret;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp = *begin_list;
	while (tmp)
	{
		tmp2 = *begin_list;
		while (tmp2)
		{
			tmp3 = *begin_list;
			while (tmp3->next)
			{
				if (cmp(tmp3->data, tmp3->next->data) > 0)
					swap_list(&tmp3->data, &tmp3->next->data);
				tmp3 = tmp3->next;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
