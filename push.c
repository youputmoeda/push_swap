/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:48:42 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/10 18:46:33 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **rece, t_list **donor, int print_p)
{
	t_list	*tmp;

	if (!rece || !(*donor) || !donor)
		return ;
	tmp = (*donor);
	(*donor) = (*donor)->next;
	tmp->next = NULL;
	tmp->next = (*rece);
	(*rece) = tmp;
	if (print_p == 1)
		write(STDOUT_FILENO, "pa\n", 3);
	else if (print_p == 2)
		write(STDOUT_FILENO, "pb\n", 3);
}
