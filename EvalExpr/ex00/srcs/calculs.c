/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 19:58:21 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/23 23:37:11 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

long	ft_sub(long x, long y)
{
	return (x - y);
}

long	ft_add(long x, long y)
{
	return (x + y);
}

long	ft_div(long x, long y)
{
	return (x / y);
}

long	ft_mul(long x, long y)
{
	return (x * y);
}

long	ft_mod(long x, long y)
{
	return (x % y);
}
