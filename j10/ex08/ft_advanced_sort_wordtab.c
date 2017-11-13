/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 10:30:14 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/18 08:18:18 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		size_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	swap_line(char **tab, char **tab1)
{
	char	*c;

	c = *tab;
	*tab = *tab1;
	*tab1 = c;
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

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < size_tab(tab))
	{
		j = 0;
		while (j < size_tab(tab))
		{
			k = j;
			while (k > 0)
			{
				if (cmp(tab[k], tab[k - 1]) < 0)
					swap_line(&tab[k], &tab[k - 1]);
				k--;
			}
			j++;
		}
		i++;
	}
}
