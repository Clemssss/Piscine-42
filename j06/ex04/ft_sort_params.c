/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:26:52 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/11 15:14:17 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

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

int		ft_strcmp(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i] != s2[j])
			return (s1[i] - s2[j]);
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

void	swap_tab(char **tab1, char **tab2)
{
	char	*tmp;

	tmp = *tab1;
	*tab1 = *tab2;
	*tab2 = tmp;
}

void	print_args(int ac, char **av)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	int		b;

	j = 0;
	while (j < ac)
	{
		i = 0;
		while (i < ac)
		{
			b = i;
			while (b > 0)
			{
				if (ft_strcmp(av[i], av[i - 1]) < 0)
					swap_tab(&av[i], &av[i - 1]);
				b--;
			}
			i++;
		}
		j++;
	}
	print_args(ac, av);
	return (0);
}
