/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:29:09 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/29 17:04:33 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	resolve(t_list **a, t_list **b)
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

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	t_list	*tmp;

	if (argc < 2 || !check(argc, argv))
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
	i = 0;
	tmp = a;
	if (!is_sort(&a))
		resolve(&a, &b);
	printf("THIS IS A:\n");
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
	printf("THIS IS B:\n");
	while (b)
	{
		ft_printf("%d\n", b->content);
		b = b->next;
	}
}
