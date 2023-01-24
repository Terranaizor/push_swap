/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 12:07:51 by nradin            #+#    #+#             */
/*   Updated: 2023/01/21 14:45:30 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_stack_sort_three(t_stack **a)
{
	t_stack	*last;

	last = ft_stack_last(*a);
	if ((*a)->value > ((*a)->next)->value && (*a)->value > last->value)
	{
		ft_stack_rotate(a, 'a');
		if ((*a)->value > ((*a)->next)->value)
			ft_stack_swap(a, 'a');
	}
	else if ((*a)->value < ((*a)->next)->value && (*a)->value < last->value)
	{
		if (((*a)->next)->value > last->value)
		{
			ft_stack_reverse_rotate(a, 'a');
			ft_stack_swap(a, 'a');
		}
	}
	else
	{
		if ((*a)->value > ((*a)->next)->value)
			ft_stack_swap(a, 'a');
		else
			ft_stack_reverse_rotate(a, 'a');
	}
}

void	push_back_sorted(t_stack **a, t_stack **b)
{
	t_transf_price	*prices;
	int				low;
	int				size;

	size = ft_stack_size(*b);
	prices = (t_transf_price *)calloc(sizeof(t_transf_price), size);
	while (ft_stack_size(*b) > 0)
	{
		low = check_rotate_values(prices, *a, *b);
		double_rotations(prices, low, a, b);
		single_rotations(prices, low, a, b);
		ft_stack_push(b, a, 'a');
	}
	free(prices);
}

void	ft_push_swap(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (ft_stack_size(*a) < 2)
	{
		if ((*a) && (*a)->next && (*a)->value > ((*a)->next)->value)
			ft_stack_swap(a, 'a');
		return ;
	}
	else if (ft_stack_size(*a) == 3)
		ft_stack_sort_three(a);
	else
	{
		if (ft_stack_size(*a) > 6)
			push_not_lis(a, &b);
		else
		{
			while (ft_stack_size(*a) > 3)
				ft_stack_push(a, &b, 'b');
			ft_stack_sort_three(a);
		}
		push_back_sorted(a, &b);
		rotate_on_top(a, ft_stack_lowest_value(*a));
	}
	return ;
}

// int	ft_check_up(t_stack *a, int value)
// {
// 	t_stack	*cur;
// 	int		i;

// 	cur = a;
// 	i = 0;
// 	while (cur && cur->value < value)
// 	{
// 		cur = cur->next;
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_check_down(t_stack *a, int value)
// {
// 	t_stack	*cur;
// 	int		i;

// 	cur = a;
// 	i = 0;
// 	while (cur && cur->value < value)
// 	{
// 		cur = cur->next;
// 		i++;
// 	}
// 	return (ft_stack_size(a) - i);
// }

// void	ft_stack_pushback(t_stack **a, t_stack **b)
// {
// 	int	i;

// 	while (ft_stack_size(*b) > 0)
// 	{
// 		i = 0;
// 		if (ft_check_up(*a, (*b)->value) <= ft_check_down(*a, (*b)->value))
// 		{
// 			while ((*b)->value > (*a)->value)
// 			{
// 				i++;
// 				ft_stack_rotate(a, 'a');
// 			}
// 			ft_stack_push(b, a, 'a');
// 			while (i > 0)
// 			{
// 				i--;
// 				ft_stack_reverse_rotate(a, 'a');
// 			}
// 		}
// 		else
// 		{
// 			while ((*b)->value < ft_stack_last(*a)->value)
// 			{
// 				i++;
// 				ft_stack_reverse_rotate(a, 'a');
// 			}
// 			ft_stack_push(b, a, 'a');
// 			ft_stack_rotate(a, 'a');
// 			while (i > 0)
// 			{
// 				i--;
// 				ft_stack_rotate(a, 'a');
// 			}
// 		}
// 	}
// }
