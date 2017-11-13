/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:04:10 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/17 10:01:57 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long int	i;

	i = nb;
	if (i < 0)
	{
		i = i * -1;
		ft_putchar('-');
	}
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}
