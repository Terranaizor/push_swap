/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:14:04 by nradin            #+#    #+#             */
/*   Updated: 2023/01/21 14:45:32 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	ft_check_lowest_rotations(t_stack *a, int value)
{
	t_stack	*cur;
	int		i;

	cur = a;
	i = 0;
	while (cur && cur->value != value)
	{
		cur = cur->next;
		i++;
	}
	if (ft_stack_size(a) - i < i)
		return (i - ft_stack_size(a));
	return (i);
}

int	ft_find_place(t_stack *a, int value)
{
	t_stack	*cur;
	int		low;
	int		is_max;

	is_max = 1;
	cur = a;
	low = INT_MAX;
	while (cur)
	{
		if (cur->value > value && cur->value <= low)
		{
			is_max = 0;
			low = cur->value;
		}
		cur = cur ->next;
	}
	if (is_max)
		low = ft_stack_lowest_value(a);
	return (ft_check_lowest_rotations(a, low));
}

void	rotate_on_top(t_stack **a, int value)
{
	int		rotates;

	rotates = ft_check_lowest_rotations(*a, value);
	while (rotates != 0)
	{
		if (rotates > 0)
		{
			ft_stack_rotate(a, 'a');
			rotates--;
		}
		else
		{
			ft_stack_reverse_rotate(a, 'a');
			rotates++;
		}
	}
}
