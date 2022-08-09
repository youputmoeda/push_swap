/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:56:09 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/09 15:58:36 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list, int print_s)
{
	t_list *new;

	if (!list || !(*list) || !(*list)->next)
		return;
	new = (*list)->next;
	(*list)->next = new->next;
	new->next = (*list);
	(*list) = new;
	if (print_s == 1)
		write(STDOUT_FILENO, "sa\n", 3);
	else if (print_s == 2)
		write(STDOUT_FILENO, "sb\n", 3);
}

void	ss(t_list **sa, t_list **sb)
{
	swap(sa, 1);
	swap(sb, 2);
	write(STDOUT_FILENO, "ss\n", 3);
}