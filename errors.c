/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 05:18:18 by joteixei          #+#    #+#             */
/*   Updated: 2022/08/12 17:06:52 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicates(char **syntax)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	while (syntax[i] != NULL)
	{
		j = i + 1;
		while (syntax[j] != NULL)
		{
			res = ft_strcmp(syntax[i], syntax[j]);
			if (res == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long long	ft_atoi_p(const char *str)
{
	int			sign;
	long long	num;

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

int	check(int len, char **syntax)
{
	int			i;
	int			j;
	long long	num;

	i = 1;
	j = 0;
	while (i < len)
	{
		if (syntax[i][0] == '-')
		{
			if (!ft_isdigit(syntax[i][1]))
				return (0);
			j = 1;		
		}
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
