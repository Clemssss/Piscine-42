/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 20:22:27 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/23 23:27:02 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

typedef	struct			s_ptr_tab
{
	long				opp;
	long				(*f)(long, long);
}						t_ptr_tab;

typedef	struct			s_operator
{
	char				data;
	struct s_operator	*next;
}						t_operator;

typedef struct			s_operand
{
	char				type;
	int					rank;
}						t_operand;

t_operator				*ft_create_elem(char data);
void					ft_list_push_front(t_operator **begin_list, char data);
long					ft_sub(long x, long y);
long					ft_add(long x, long y);
long					ft_div(long x, long y);
long					ft_mul(long x, long y);
long					ft_mod(long x, long y);
t_operator				*remp_list_operator(char *str);
void					ft_putchar(char c);
void					ft_putnbr(int nbr);
int						ft_strlen(char *str);
long					ft_atoi(char *str);
int						eval_expr(char *str);
int						result(char *str);
char					*check_op(char c, t_operator **op);
char					*destack_fin(t_operator *op);
void					ft_list_push_front(t_operator **begin_list, char data);
char					*destack_op(t_operator **op, char c);
long					resolve(long *tab);

#endif
