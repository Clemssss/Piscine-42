/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:17:00 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/05 15:19:15 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
