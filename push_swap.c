/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:29:09 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/30 18:52:07 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void resolve(t_list **a, t_list **b)
{
	if (ft_lstsize((*a)) == 2)
		sort_2(a);
	else if (ft_lstsize((*a)) == 3)
		sort_3(a);
	else if (ft_lstsize((*a)) == 4 || ft_lstsize((*a)) == 5)
	{
		sort_5(a, b);
		sort_3(a);
		push(a, b, 1);
		push(a, b, 1);
	}
	else
		sort_all(a, b);
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	int i;

	if (argc < 2)
		return (1);
	if (!check(argc, argv))
	{
		printf("Error\n");
		return (1);
	}
	i = 1;
	a = NULL;
	b = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&a, ft_lstnew((void *)(long)ft_atoi(argv[i])));
		i++;
	}
	if (!is_sort(&a))
		resolve(&a, &b);
	ft_lstclear(&a, NULL);
}
