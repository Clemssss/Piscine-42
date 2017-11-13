/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:18:28 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/20 20:34:01 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*tmp;

	tmp = ft_create_elem(data);
	tmp->next = *begin_list;
	*begin_list = tmp;
}

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (i < ac)
	{
		ft_list_push_front(&tmp, av[i]);
		i++;
	}
	return (tmp);
}
