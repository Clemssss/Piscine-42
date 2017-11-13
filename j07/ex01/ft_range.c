/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 17:37:59 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/12 20:06:07 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;
	int		s;

	if (max <= min)
		return (NULL);
	tab = malloc(sizeof(int) * (max - min + 1));
	i = 0;
	s = min;
	while (i < max - min)
	{
		tab[i] = s;
		i++;
		s++;
	}
	return (tab);
}
