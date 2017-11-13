/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clegirar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/15 09:58:39 by clegirar          #+#    #+#             */
/*   Updated: 2017/07/16 18:18:47 by clegirar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUDOKU_H
# define FT_SUDOKU_H

char			*ft_strdup(char *str);
int				ft_strlen(char *str);
int				ft_sudoku(char **av);
int				algo(char *av, char *tab, int pos);
int				check_av(char *str, int pos);
int				ft_check(char *tab, char c, int pos);

#endif
