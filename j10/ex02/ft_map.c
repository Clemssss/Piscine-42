/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 20:52:46 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/18 08:21:22 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*ret;
	int		i;
	int		j;

	if ((ret = malloc(sizeof(int) * (length + 1))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < length)
	{
		ret[j] = f(tab[i]);
		j++;
		i++;
	}
	ret[j] = '\0';
	return (ret);
}
