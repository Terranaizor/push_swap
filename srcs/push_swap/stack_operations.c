/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:04:14 by nradin            #+#    #+#             */
/*   Updated: 2023/01/24 18:07:22 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_stack_push(t_stack **a, t_stack **b, char output)
{
	t_stack	*temp;

	if (*a)
	{
		temp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = temp;
	}
	if (output)
		ft_printf("p%c\n", output);
}

void	ft_stack_swap(t_stack **a, char output)
{
	t_stack	*temp;

	if (*a && (*a)->next)
	{
		temp = (*a);
		(*a) = (*a)->next;
		temp->next = (*a)->next;
		(*a)->next = temp;
	}
	if (output)
		ft_printf("s%c\n", output);
}

void	ft_stack_rotate(t_stack **a, char output)
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
	if (output)
		ft_printf("r%c\n", output);
}

void	ft_stack_reverse_rotate(t_stack **a, char output)
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
	if (output)
		ft_printf("rr%c\n", output);
}
