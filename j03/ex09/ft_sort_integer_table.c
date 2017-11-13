/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 15:21:11 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/05 16:28:30 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_int(int *a, int *b)
{
	int		c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_integer_table(int *tab, int size)
{
	int		b;
	int		a;

	a = 1;
	while (a < size)
	{
		b = a;
		while (b > 0)
		{
			if (tab[b - 1] > tab[b])
				swap_int(&tab[b - 1], &tab[b]);
			b--;
		}
		a++;
	}
}
