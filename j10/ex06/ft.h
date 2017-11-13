/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:16:24 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/17 09:45:59 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef	struct	s_ptr_tab
{
	char		*operateur;
	int			(*f)(int, int);
}				t_ptr_tab;

int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str);
void			ft_putnbr(int nb);
void			ft_putchar(char c);
void			ft_putstr(char *str);

int				sub(int a, int b);
int				add(int a, int b);
int				mul(int a, int b);
int				div(int a, int b);
int				mod(int a, int b);

#endif
