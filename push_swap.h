/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:29:41 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/12 19:08:49 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*
** swap.c
*/
void		swap(t_list **list, int print_s);
void		ss(t_list **sa, t_list **sb);

/*
** push.c
*/
void		push(t_list **rece, t_list **donor, int print_p);

/**
** rotate.c
*/
void		rotate(t_list **list, int print_r);
void		rr(t_list **a, t_list **b);
void		r_rotate(t_list **list, int print_rr);
void		rrr(t_list **a, t_list **b);

/*
** errors.c
*/
int			duplicates(char **syntax);
int			check(int len, char **syntax);
long long	ft_atoi_p(const char *str);

/*
** errors.c
*/
void		sort_3(t_list **list);
void		sort_5(t_list **a, t_list **b);

/*
** errors.c
*/
int			ft_smallest(t_list *list);

#endif