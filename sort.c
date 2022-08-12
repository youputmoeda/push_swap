/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:28:59 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/12 19:13:56 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **list)
{
	int	a;
	int	b;
	int	c;

	a = (long)(*list)->content;
	b = (long)(*list)->next->content;
	c = (long)(*list)->next->next->content;
	if (a < b && b > c && a < c)
	{
		swap(list, 1);
		rotate(list, 1);
	}
	else if (a > b && b < c && a < c)
		swap(list, 1);
	else if (a < b && b > c && a > c)
		r_rotate(list, 1);
	else if (a > b && b > c && a > c)
	{
		rotate(list, 1);
		swap(list, 1);
	}
	else if (a > b && b < c && a > c)
		rotate(list, 1);
}

void	sort_5(t_list **a, t_list **b)
{
	t_list *tmp;
	int		pos;

	tmp = (*a);
	pos = ft_smallest(tmp);
	printf("%d\n", pos);
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
	push(b, a, 2);
}
