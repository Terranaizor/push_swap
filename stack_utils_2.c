/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:04:14 by nradin            #+#    #+#             */
/*   Updated: 2023/01/18 18:33:32 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_lowest_value(t_stack	*a)
{
	int	low;

	low = INT_MAX;
	while (a)
	{
		if (a->value < low)
			low = a->value;
		a = a->next;
	}
	return (low);
}

//delete later
void	ft_putstack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->value, 1);
		ft_putchar_fd(' ', 1);
		stack = stack->next;
	}
	ft_putchar_fd('\n', 1);
}

int	*ft_stack_to_arr(t_stack *a)
{
	int	*res;
	int	i;

	res = (int *)calloc(sizeof(int), ft_stack_size(a));
	i = 0;
	while (a)
	{
		res[i] = a->value;
		a = a->next;
		i++;
	}
	return (res);
}
