/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joteixei <joteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:29:09 by joteixei          #+#    #+#             */
/*   Updated: 2022/07/27 22:05:43 by joteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_frame(t_stack *frame, char **argv)
{
	frame = (t_stack *)malloc(sizeof(t_stack));
	if (!(frame))
		exit(1);
	frame->array = argv;
	return (frame);
}

int	main(int argc, char **argv)
{
	t_stack	*frame;
	char	*str;
	int		num;

	if (argc < 2)
		return (1);
	create_frame(frame, argv);
	str = frame->array[1];
	num = ft_atoi(str);
	ft_printf("%d", num);
}
