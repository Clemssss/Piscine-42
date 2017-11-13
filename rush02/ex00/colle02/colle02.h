/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:18:46 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/22 20:02:49 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLE02_H
# define COLLE02_H

typedef	struct	s_par
{
	char		*buf;
	int			i;
	int			j;
}				t_par;

typedef	struct	s_colle
{
	char		*(*g)(int, int);
	int			(*f)(int, int);
}				t_colle;

int				colle00(int x, int y);
int				colle01(int x, int y);
int				colle02(int x, int y);
int				colle03(int x, int y);
int				colle04(int x, int y);
char			*rush00(int x, int y);
char			*rush01(int x, int y);
char			*rush02(int x, int y);
char			*rush03(int x, int y);
char			*rush04(int x, int y);
int				ft_strcmp(char *s1, char *s2);
int				nb_car(char *buf);
int				nb_line(char *buf);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
int				ft_strlen(char *str);
char			*read_file(void);

#endif
