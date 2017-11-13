/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doop.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 11:05:41 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/17 16:05:30 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOP_H
# define FT_DOOP_H

typedef	struct	s_opp
{
	char		*opp;
	int			(*f)(int, int);
}				t_opp;

void			ft_putnbr(int nb);
void			ft_putstr(char *str);
void			ft_putchar(char c);
int				ft_atoi(char *str);
int				ft_strcmp(char *s1, char *s2);
int				ft_add(int a, int b);
int				ft_sub(int a, int b);
int				ft_mul(int a, int b);
int				ft_div(int a, int b);
int				ft_mod(int a, int b);
int				ft_usage(int a, int b);

#endif
