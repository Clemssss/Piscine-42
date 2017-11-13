/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 11:46:15 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/09 14:47:26 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		count(int size)
{
	int i;
	int	j;
	int	incr;
	int	len;

	len = 3;
	i = 0;
	incr = 6;
	while (i < size)
	{
		j = 0;
		while (j < 3 + i)
		{
			if (j)
				len += 2;
			j++;
		}
		if (i + 1 >= size)
			return ((len - ((incr - 6) / 2)) / 2 - 1);
		if (i & 2 && i)
			incr += 2;
		len += incr;
		i++;
	}
	return (len / 2);
}

void	print(int x, int *len, int *space)
{
	int		i;

	i = 0;
	if (x == 0)
	{
		while (i < *space)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar('/');
	}
	else if (x == 1)
	{
		ft_putchar('\\');
		ft_putchar('\n');
	}
	else if (x == 2)
	{
		while (i < *len - 2)
		{
			ft_putchar('*');
			i++;
		}
	}
}

void	print_door(int *space, int *len, int size_door, int i)
{
	int		j;

	print(0, len, space);
	while (i < *len - 2)
	{
		if (i + size_door / 2 == (*len - 2) / 2 && *space <= size_door - 1)
		{
			j = 0;
			while (j < size_door)
			{
				if (size_door >= 5 && size_door / 2 == *space
						&& j + 2 == size_door)
					ft_putchar('$');
				else
					ft_putchar('|');
				i++;
				j++;
			}
			i--;
		}
		else
			ft_putchar('*');
		i++;
	}
	print(1, len, space);
}

void	sastantua_loop(int i, int *len, int size_door, int *space)
{
	int		j;

	j = 0;
	while (j < 3 + i)
	{
		if (j)
			*len = *len + 2;
		if (*space + 1 <= size_door)
			print_door(space, len, size_door, 0);
		else
		{
			print(0, len, space);
			print(2, len, space);
			print(1, len, space);
		}
		*space = *space - 1;
		j++;
	}
}

void	sastantua(int size)
{
	int		i;
	int		incr;
	int		len;
	int		space;
	int		size_door;

	space = count(size);
	len = 3;
	i = 0;
	incr = 6;
	size_door = 1;
	while (i < size)
	{
		sastantua_loop(i, &len, size_door, &space);
		if (i + 1 >= size)
			return ;
		if (i % 2 == 0 && i)
			incr += 2;
		if (i % 2 && i)
			size_door += 2;
		len += incr;
		space -= incr / 2 - 1;
		i++;
	}
}
