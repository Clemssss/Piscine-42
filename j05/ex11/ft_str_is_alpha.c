/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 20:51:17 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/06 22:00:18 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int		i;

	if (!(str))
		return (1);
	i = 0;
	while (str[i])
	{
		if ((str[i] < 65 || str[i] > 90)
			&& (str[i] < 97 || str[i] > 122))
			return (0);
		i++;
	}
	return (1);
}