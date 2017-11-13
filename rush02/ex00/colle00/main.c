/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 09:14:17 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/22 10:09:52 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colle00.h"

int		ft_sign(int sign, char c)
{
	if (c == '-')
		sign = -1;
	else
		sign = 1;
	return (sign);
}

int		ft_atoi(char *str)
{
	int		ret;
	int		sign;
	int		i;

	i = 0;
	ret = 0;
	sign = 1;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = ft_sign(sign, str[i]);
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (ret);
}

int		main(int ac, char **av)
{
	if (ac != 3)
		return (-1);
	rush(ft_atoi(av[1]), ft_atoi(av[2]));
	return (0);
}
