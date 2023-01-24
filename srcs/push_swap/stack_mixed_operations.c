/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_mixed_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:04:14 by nradin            #+#    #+#             */
/*   Updated: 2023/01/24 18:04:44 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_stack_swap_both(t_stack **a, t_stack **b, char output)
{
	ft_stack_swap(a, 0);
	ft_stack_swap(b, 0);
	if (output)
		ft_printf("ss\n");
}

void	ft_stack_rotate_both(t_stack **a, t_stack **b, char output)
{
	ft_stack_rotate(a, 0);
	ft_stack_rotate(b, 0);
	if (output)
		ft_printf("rr\n");
}

void	ft_stack_reverse_rotate_both(t_stack **a, t_stack **b, char output)
{
	ft_stack_reverse_rotate(a, 0);
	ft_stack_reverse_rotate(b, 0);
	if (output)
		ft_printf("rrr\n");
}
