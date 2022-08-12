/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:41:50 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/12 20:04:52 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_smallest(t_list *list)
{
	t_list *tmp;
	t_list *smaller;
	int count;
	
	count = 0;
	tmp = list;
	smaller = list;
	while (tmp->next != NULL)
	{
		if (tmp->content < smaller->content)
			smaller = tmp;
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp->content != smaller->content)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

void	ft_push(t_list **a, t_list **b)
{
	
}