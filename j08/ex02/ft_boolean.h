/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 13:58:54 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/13 11:10:57 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

typedef	int		t_bool;
# define EVEN(nbr)	(nbr % 2)
# define TRUE	0
# define FALSE	1
# define SUCCESS	0
# define EVEN_MSG	"I have an odd number of arguments.\n"
# define ODD_MSG	"I have an even number of arguments.\n"

#endif
