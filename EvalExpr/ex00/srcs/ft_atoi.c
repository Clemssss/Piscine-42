/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:05:05 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/23 21:17:03 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_sign(long sign, char c)
{
	if (c == '-')
		sign = -1;
	else
		sign = 1;
	return (sign);
}

long	ft_atoi(char *str)
{
	long	ret;
	long	sign;
	int		i;

	ret = 0;
	sign = 1;
	i = 0;
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
