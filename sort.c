/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:28:59 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/11 16:13:31 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **list)
{
	t_list	*tmp;

	if (!((*list)->next) || !(*list) || !list)
		return ;
	tmp = (*list);
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			swap(&tmp, 1);
		tmp = tmp->next;
	}
	printf("%ld\n", (long)tmp->content);
}
