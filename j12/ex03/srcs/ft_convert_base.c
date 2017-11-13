/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 11:34:48 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/20 14:14:31 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	s;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	while (i < len / 2)
	{
		s = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = s;
		i++;
	}
	return (str);
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

char	*ft_convert_base(int nb, char *base_to)
{
	int		res;
	int		j;
	char	*tmp;

	j = 0;
	res = 0;
	tmp = malloc(sizeof(char) * (20));
	while (nb != 0)
	{
		res = (nb % ft_strlen(base_to));
		tmp[j++] = base_to[res];
		nb = nb / ft_strlen(base_to);
	}
	tmp = ft_strrev(tmp);
	return (tmp);
}
