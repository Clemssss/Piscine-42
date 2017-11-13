/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:25:59 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/17 16:12:39 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"

int		ft_div(int a, int b)
{
	return (a / b);
}

int		ft_mod(int a, int b)
{
	return (a % b);
}

int		ft_usage(int a, int b)
{
	(void)a;
	(void)b;
	ft_putstr("error : only [ + - * / % ] are accepted.\n");
	return (0);
}
