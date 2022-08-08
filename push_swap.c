/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:29:09 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/08 18:09:51 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void swap(t_list **list)
{
	t_list *new;

	if (!list || (*list) || !(*list)->next)
		return ;
	new = (*list)->next;
	(*list)->next = new->next;
	new->next = (*list);
	(*list) = new;
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	char *str;
	int i;

	if (argc < 2)
		return (1);
	i = 1;
	a = NULL;
	b = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&a, ft_lstnew((void *)(long)ft_atoi(argv[i])));
		i++;
	}
	swap(&a);
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	} 
}