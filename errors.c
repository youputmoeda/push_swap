/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 05:18:18 by joteixei          #+#    #+#             */
/*   Updated: 2022/09/01 17:24:57 by joteixei         ###   ########.fr       */
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
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += (sign * (*(str++) - 48));
	}
	return (num);
}

int	helper(int i, int j, char **syntax)
{
	int	is_valid;
	int	len;

	len = 0;
	is_valid = 0;
	if (syntax[i][0] == '-')
	{
		if (!ft_isdigit(syntax[i][1]))
			return (0);
		j = 1;
	}
	while (syntax[i][j] != '\0')
	{
		if (!is_valid && syntax[i][j] != '0')
			len = is_valid++;
		else
			len++;
		if (!ft_isdigit(syntax[i][j]))
			return (0);
		j++;
	}
	return (len < 11);
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
		if (syntax[i][j] == '\0')
			return (0);
		if (!(helper(i, j, syntax)))
			return (0);
		num = ft_atoi_p(syntax[i]);
		if (!(num >= LONG_MIN && num <= LONG_MAX))
			return (0);
		i++;
		j = 0;
	}
	return (1);
}
