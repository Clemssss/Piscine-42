/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 18:47:04 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/10 13:52:35 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		k;
	char	*result;
	int		save;

	i = 0;
	result = NULL;
	if (to_find[0] != '\0')
	{
		while (str[i])
		{
			k = 0;
			save = i;
			while (str[i++] == to_find[k++])
				if (to_find[k] == '\0')
					return (str + save);
			if (to_find[k] != str[i])
				i = (i - k) + 1;
		}
	}
	else if (to_find[0] == '\0')
		result = str;
	return (result);
}
