/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 20:21:09 by nradin            #+#    #+#             */
/*   Updated: 2023/01/18 18:33:43 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_lowest_rotates(t_stack *a, int value)
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
