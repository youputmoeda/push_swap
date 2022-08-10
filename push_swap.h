/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:29:41 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/10 18:46:01 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

/*
** swap.c
*/
void	swap(t_list **list, int print_s);
void	ss(t_list **sa, t_list **sb);

/*
** push.c
*/
void	push(t_list **rece, t_list **donor, int print_p);

/**
** rotate.c
*/
void	rotate(t_list **list, int print_r);
void	rr(t_list **a, t_list **b);
void	r_rotate(t_list **list, int print_rr);
void	rrr(t_list **a, t_list **b);
#endif