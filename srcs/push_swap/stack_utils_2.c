/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:04:14 by nradin            #+#    #+#             */
/*   Updated: 2023/01/25 13:29:07 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

void	ft_stack_clear(t_stack **a)
{
	t_stack	*cur;
	t_stack	*next;

	cur = *a;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*a = NULL;
}

int	ft_stack_is_sorted(t_stack *a)
{
	t_stack	*prev;

	if (!a)
		return (1);
	prev = a;
	a = a->next;
	while (a)
	{
		if (a->value < prev->value)
			return (0);
		prev = a;
		a = a->next;
	}
	return (1);
}
