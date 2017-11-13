/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:05:56 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/07 14:17:19 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index > 46)
		return (0);
	else if (index <= 1)
		return (index);
	else
		index = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (index);
}
