/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 16:06:13 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/23 11:29:07 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "colle02.h"

char	*ft_strdup_custom(char *str)
{
	char	*buf;
	int		i;

	if ((buf = malloc(sizeof(char) * (ft_strlen(str) + 2))) == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		buf[i] = str[i];
		i++;
	}
	buf[i + 1] = '\0';
	free(str);
	return (buf);
}

char	*read_file(void)
{
	char	*str;
	int		i;
	char	buf[1];

	if ((str = malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	i = 0;
	while (read(0, buf, 1) && buf[0] != '\0')
	{
		str[i] = buf[0];
		str[i + 1] = '\0';
		if ((str = ft_strdup_custom(str)) == NULL)
			return (NULL);
		i++;
	}
	str[i] = '\0';
	return (str);
}
