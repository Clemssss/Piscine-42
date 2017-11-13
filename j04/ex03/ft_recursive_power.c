/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:00:05 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/09 16:14:32 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int		result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	power--;
	result = nb * ft_recursive_power(nb, power);
	return (result);
}
