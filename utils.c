/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:41:50 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/31 14:18:12 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_list **list)
{
	t_list	*tmp;
	int		count;

	tmp = (*list);
	count = 0;
	while (tmp->next != NULL)
	{
		if ((long)tmp->content > (long)tmp->next->content)
			count++;
		tmp = tmp->next;
	}
	if (count == 0)
		return (1);
	else
		return (0);
}

int	ft_smallest(t_list *list)
{
	t_list	*tmp;
	t_list	*smaller;
	int		count;

	count = 0;
	tmp = list;
	smaller = list;
	while (tmp)
	{
		if ((long)tmp->content < (long)smaller->content)
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

void	ft_org_push(t_list **a, t_list **b, int pos)
{
	t_list	*tmp;

	tmp = (*a);
	if (pos > 2)
	{
		if (ft_lstsize(tmp) == 5)
			pos = 5 - pos;
		else
			pos = 4 - pos;
		while (pos)
		{
			r_rotate(a, 1);
			pos--;
		}
	}
	else
	{
		while (pos)
		{
			rotate(a, 1);
			pos--;
		}
	}
	push(b, a, 2);
}
