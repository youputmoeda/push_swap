/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:49:30 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/09 19:13:21 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **list, int print_r)
{
	t_list *tmp;
	t_list *ptr;

	ptr = (*list);
	(*list) = (*list)->next;
	tmp = (*list);
	while (tmp->next != NULL)
		tmp = tmp->next;
	ptr->next = NULL;
	tmp->next = ptr;
	if (print_r == 1)
		write(STDOUT_FILENO, "ra\n", 3);
	else if (print_r == 2)
		write(STDOUT_FILENO, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a, 1);
	rotate(b, 2);
	write(STDOUT_FILENO, "rr\n", 3);
}

void	r_rotate(t_list **list, int print_rr)
{
	t_list *tmp;

	tmp = (*list);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = (*list);
	(*list) = tmp->next;
	tmp->next = NULL;
	if (print_rr == 1)
		write(STDOUT_FILENO, "rra\n", 4);
	else if (print_rr == 2)
		write(STDOUT_FILENO, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	r_rotate(a, 1);
	r_rotate(b, 2);
	write(STDOUT_FILENO, "rrr\n", 4);
}