/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:04:14 by nradin            #+#    #+#             */
/*   Updated: 2023/01/18 18:33:27 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push(t_stack **a, t_stack **b, char stack)
{
	t_stack	*temp;

	if (*a)
	{
		temp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = temp;
	}
	if (stack)
		ft_printf("p%c\n", stack);
}

void	ft_stack_swap(t_stack **a, char stack)
{
	t_stack	*temp;

	if (*a && (*a)->next)
	{
		temp = (*a);
		(*a) = (*a)->next;
		temp->next = (*a)->next;
		(*a)->next = temp;
	}
	if (stack)
		ft_printf("s%c\n", stack);
}

void	ft_stack_rotate(t_stack **a, char stack)
{
	t_stack	*last;
	t_stack	*temp;

	if (*a && (*a)->next)
	{
		last = ft_stack_last(*a);
		last->next = *a;
		temp = (*a);
		(*a) = (*a)->next;
		temp->next = NULL;
	}
	if (stack)
		ft_printf("r%c\n", stack);
}

void	ft_stack_reverse_rotate(t_stack **a, char stack)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (*a && (*a)->next)
	{
		last = ft_stack_last(*a);
		penultimate = ft_stack_penultimate(*a);
		last->next = *a;
		(*a) = last;
		penultimate->next = NULL;
	}
	if (stack)
		ft_printf("rr%c\n", stack);
}
