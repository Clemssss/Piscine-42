/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 12:39:55 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/26 22:20:08 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef	struct	s_stock
{
	int			**tab;
	int			i;
	int			j;
}				t_stock;

typedef	struct	s_chars
{
	int			nb_lines;
	int			nb_column;
	int			nbr;
	char		empty;
	char		obstacle;
	char		full;
}				t_chars;

typedef	struct	s_pos
{
	int			s_x;
	int			s_y;
	int			car;
	int			pos_x;
	int			pos_y;
}				t_pos;

int				**demin(int **tab, t_chars chars, t_pos *pos);
void			print_croix(int **tab, t_chars chars, t_pos pos);
void			ft_putchar(char c);
int				read_file(int ac, char **av);
int				ft_strlen(char *str);
int				algo(int **tab, t_chars chars, char *buf);
void			ft_putstr(char *str);
int				**ft_split_whitespaces(char *str, t_chars *chars);
int				nb_lines(char *str);
int				nb_car(char *str, int x);
int				ft_atoi(char *str);

#endif
