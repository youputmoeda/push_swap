/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:29:09 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/10 19:29:36 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int duplicates(char **syntax)
{
	int i;
	int j;
	int k;
	int count;

	i = 0;
	while (syntax[++i])
	{
		j = 0;
		count = 1;
		k = 0;
		while (syntax[++j] && count)
		{
			if (i != j && syntax[i] != syntax[j])
				count = 0;
			k++;
		}
		if (count >= 1)
			return (0);
	}
	return (1);
}

long long ft_atoi_p(const char *str)
{
	int sign;
	long long num;

	sign = 1;
	num = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
	}
	while (*str > 47 && *str < 58)
	{
		num *= 10;
		num += (sign * (*(str++) - 48));
	}
	return (num);
}

int check(int len, char **syntax)
{
	int i;
	int j;
	long long num;

	i = 1;
	j = 0;
	while (i < len)
	{
		if (syntax[i][0] == '-')
			j = 1;
		while (syntax[i][j] != '\0')
		{
			if (!ft_isdigit(syntax[i][j]))
				return (0);
			j++;
		}
		num = ft_atoi_p(syntax[i]);
		if (!(num >= LONG_MIN && num <= LONG_MAX))
			return (0);
		i++;
		j = 0;
	}
	if (!duplicates(syntax))
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;
	char *str;
	int i;
	int checker;

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
