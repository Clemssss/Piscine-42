/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 17:39:01 by clegirar          #+#    #+#             */
/*   Updated: 2017/12/01 19:30:46 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		algo(int **tab, t_chars chars, char *buf)
{
	t_pos	pos;
	int		i;

	pos.pos_x = 1;
	pos.pos_y = 0;
	pos.car = 1;
	tab = demin(tab, chars, &pos);
	print_croix(tab, chars, pos);
	i = 0;
	while (buf[i])
		buf[i++] = '\0';
	return (0);
}
