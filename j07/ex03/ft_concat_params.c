/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 19:42:07 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/12 16:00:37 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		size_str(char **tab)
{
	int		i;
	int		j;
	int		len;

	i = 1;
	len = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			len++;
			j++;
		}
		len++;
		i++;
	}
	return (len);
}

char	*ft_concat_params(int argc, char **argv)
{
	char	*str;
	int		i;
	int		j;
	int		x;

	str = malloc(sizeof(char) * (size_str(argv)));
	i = 1;
	x = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
			str[x++] = argv[i][j++];
		if (i + 1 != argc)
			str[x++] = '\n';
		i++;
	}
	str[x] = '\0';
	return (str);
}
