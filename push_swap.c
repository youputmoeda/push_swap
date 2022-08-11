/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:29:09 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/11 15:47:33 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

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
	printf("ATENÇÃO:\n");
	sort_3(&a);
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
