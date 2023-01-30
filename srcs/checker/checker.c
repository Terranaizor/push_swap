/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:48:11 by nradin            #+#    #+#             */
/*   Updated: 2023/01/25 12:31:50 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	read_operations(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "sa\n", 4))
		ft_stack_swap(a, 0);
	else if (!ft_strncmp(op, "sb\n", 4))
		ft_stack_swap(b, 0);
	else if (!ft_strncmp(op, "ss\n", 4))
		ft_stack_swap_both(b, 0, 0);
	else if (!ft_strncmp(op, "pa\n", 4))
		ft_stack_push(b, a, 0);
	else if (!ft_strncmp(op, "pb\n", 4))
		ft_stack_push(a, b, 0);
	else if (!ft_strncmp(op, "ra\n", 4))
		ft_stack_rotate(a, 0);
	else if (!ft_strncmp(op, "rb\n", 4))
		ft_stack_rotate(b, 0);
	else if (!ft_strncmp(op, "rr\n", 4))
		ft_stack_rotate_both(a, b, 0);
	else if (!ft_strncmp(op, "rra\n", 5))
		ft_stack_reverse_rotate(a, 0);
	else if (!ft_strncmp(op, "rrb\n", 5))
		ft_stack_reverse_rotate(b, 0);
	else if (!ft_strncmp(op, "rrr\n", 5))
		ft_stack_reverse_rotate_both(a, b, 0);
	else
		return (0);
	return (1);
}

void	print_result(t_stack *a, t_stack *b)
{
	if (ft_stack_is_sorted(a) && !b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	b = NULL;
	a = parse_stack(argc, argv);
	op = get_next_line(0);
	while (op)
	{
		if (!read_operations(&a, &b, op))
		{
			free(op);
			throw_error(&a);
		}
		free(op);
		op = get_next_line(0);
	}
	free(op);
	print_result(a, b);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}
