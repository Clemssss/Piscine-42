/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:34:48 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/12 21:55:58 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0') * sign;
		i++;
	}
	return (ret);
}

int		ft_iterative_power(int nb, int power)
{
	int		result;

	result = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*stock_nbr(int res)
{
	int		len;
	int		nb;
	int		i;
	char	*tmp;

	len = 0;
	nb = res;
	while (nb > 0)
	{
		len++;
		nb = nb / 10;
	}
	tmp = malloc(sizeof(char) * (len + 1));
	i = len - 1;
	while (i >= 0)
	{
		tmp[i] = (res % 10) + '0';
		res = res / 10;
		i--;
	}
	return (tmp);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		res;
	int		j;

	nb = ft_atoi(nbr);
	j = 0;
	res = 0;
	while (j < ft_strlen(nbr))
	{
		res = res + (nb % 10) * ft_iterative_power(ft_strlen(base_from), j);
		nb = nb / 10;
		j++;
	}
	nb = res;
	j = 1;
	res = 0;
	while (nb != 0)
	{
		res = res + (nb % ft_strlen(base_to)) * j;
		nb = nb / ft_strlen(base_to);
		j *= 10;
	}
	nbr = stock_nbr(res);
	return (nbr);
}
