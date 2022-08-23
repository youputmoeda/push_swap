/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 22:45:17 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/20 22:46:50 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	implement_order(t_list **list)
{
	t_list	*sort_list;
	t_list	*index;
	t_list	*helper;

	sort_list = (*list);
	index = NULL;
	helper = NULL;
	while (sort_list->content)
	{
		index = sort_list->next;
		while (index->content)
		{
			if (sort_list->content > index->content)
			{
				helper = sort_list;
				sort_list->content = index->content;
				index = helper;
			}
			index = index->next;
		}
		sort_list = sort_list->next;
	}
}

void	empty_list(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		size;

	tmp = (*b);
	size = ft_lstsize(tmp);
	while (size != 0)
	{
		push(a, b, 1);
		size--;
	}
}

void	organize_index(t_list **a, t_list **b, int size)
{
	int		max_num;
	int		max_bits;
	int		i;
	int		j;

	max_num = size - 1;
	max_bits = 0;
	i = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((long)(*a)->content >> i) & 1 == 1)
				rotate(a, 1);
			else
				push(b, a, 2);
			j++;
		}
		empty_list(a, b);
		i++;
	}
}
