/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 18:17:14 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/12 16:00:08 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		s;

	if (min >= max)
		return (0);
	*range = malloc(sizeof(int) * (max - min + 1));
	i = 0;
	s = min;
	while (i < max - min)
	{
		range[0][i] = s;
		i++;
		s++;
	}
	return (max - min);
}
