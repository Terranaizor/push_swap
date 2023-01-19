/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:59:03 by nradin            #+#    #+#             */
/*   Updated: 2023/01/18 19:10:28 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_transf_price {
	int	moves[2];
	int	value;
}t_transf_price;

void	push_swap(void);

t_stack	*ft_stacknew(int value);
void	ft_stack_add(t_stack **stack, t_stack *new);
void	ft_putstack(t_stack *stack);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stack_penultimate(t_stack *stack);
int		ft_stack_size(t_stack *stack);
int		ft_stack_lowest_value(t_stack	*a);
int		*ft_stack_to_arr(t_stack *a);

void	ft_stack_push(t_stack **a, t_stack **b, char stack);
void	ft_stack_swap(t_stack **a, char stack);
void	ft_stack_rotate(t_stack **a, char stack);
void	ft_stack_reverse_rotate(t_stack **a, char stack);
void	ft_stack_swap_both(t_stack **a, t_stack **b);
void	ft_stack_rotate_both(t_stack **a, t_stack **b);
void	ft_stack_reverse_rotate_both(t_stack **a, t_stack **b);

int		ft_check_lowest_rotations(t_stack *a, int value);
int		ft_find_place(t_stack *a, int value);
void	rotate_on_top(t_stack **a, int value);

int		check_rotate_values(t_transf_price *prices, t_stack *a, t_stack *b);
void	double_rotations(t_transf_price *prices, \
		int index, t_stack **a, t_stack **b);
void	single_rotations(t_transf_price *prices, \
		int index, t_stack **a, t_stack **b);

void	ft_stack_sort_three(t_stack **a);
void	ft_push_swap(t_stack **a);
void	push_not_lis(t_stack **a, t_stack **b);

#endif
