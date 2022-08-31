/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 22:45:17 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/31 14:51:15 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void implement_order(t_list **list, int size, int before, int pos)
{
	t_list *tmp;
	t_list *min;
	int min_n;

	min_n = LONG_MAX;
	tmp = (*list);
	while (tmp)
	{
		if (min_n >= (long)tmp->content && ((long)tmp->content > before
			|| (before == LONG_MIN && (long)tmp->content == LONG_MIN && pos == 0)))
		{
			min = tmp;
			min_n = (long)tmp->content;
		}
		tmp = tmp->next;
	}
	if (pos != size - 1)
		implement_order(list, size, min_n, pos + 1);
	min->content = (void *)(long)pos;
}

void empty_list(t_list **a, t_list **b)
{
	t_list *tmp;
	int size;

	tmp = (*b);
	size = ft_lstsize(tmp);
	while (size != 0)
	{
		push(a, b, 1);
		size--;
	}
}

void organize_index(t_list **a, t_list **b, int size)
{
	int max_num;
	int max_bits;
	int i;
	int j;

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
			if ((((long)(*a)->content >> i) & 1) == 1)
				rotate(a, 1);
			else
				push(b, a, 2);
			j++;
		}
		empty_list(a, b);
		i++;
	}
}
