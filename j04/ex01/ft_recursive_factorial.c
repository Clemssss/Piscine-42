/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 11:40:22 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/06 13:46:48 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int		x;

	x = 0;
	if (nb < 0 || nb >= 13)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	if (nb > 1)
		x = nb * ft_recursive_factorial(nb - 1);
	return (x);
}
