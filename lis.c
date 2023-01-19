/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:47:25 by nradin            #+#    #+#             */
/*   Updated: 2023/01/18 18:57:30 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_replace(int *lis, int left, int right, int key)
{
	int	mid;

	mid = (left + right) / 2;
	while (left <= right)
	{
		if (lis[mid] > key)
			right = mid - 1;
		else if (lis[mid] == key)
			return (mid);
		else if (mid + 1 <= right && lis[mid + 1] >= key)
		{
			lis[mid + 1] = key;
			return (mid + 1);
		}
		else
			left = mid + 1;
		mid = (left + right) / 2;
	}
	if (mid == left)
	{
		lis[mid] = key;
		return (mid);
	}
	lis[mid + 1] = key;
	return (mid + 1);
}

int	*lis_sub(int size, int lis_length, int *arr, int *index)
{
	int	i;
	int	tmp;
	int	*answer;

	answer = (int *)malloc((lis_length + 2) * sizeof(int));
	i = size - 1;
	tmp = lis_length;
	while (i >= 0)
	{
		if (index[i] == tmp)
			answer[tmp--] = arr[i];
		i--;
	}
	return (answer);
}

int	*get_lis(int *arr, int size, int *lis_size)
{
	int	i;
	int	lis_length;
	int	*answer;
	int	*lis;
	int	*index;

	lis_length = -1;
	lis = (int *)malloc(sizeof(int) * size);
	index = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
		lis[i++] = INT_MAX;
	i = 0;
	while (i < size)
	{
		index[i] = search_replace(lis, 0, i, arr[i]);
		if (lis_length < index[i])
			lis_length = index[i];
		i++;
	}
	answer = lis_sub(size, lis_length, arr, index);
	*lis_size = lis_length + 1;
	free(lis);
	free(index);
	return (answer);
}

int	int_in_arr(int n, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == n)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	push_not_lis(t_stack **a, t_stack **b)
{
	int		*lis;
	int		lis_size;
	int		i;
	int		*arr;

	i = ft_stack_size(*a);
	rotate_on_top(a, ft_stack_lowest_value(*a));
	arr = ft_stack_to_arr(*a);
	lis = get_lis(arr, i, &lis_size);
	while (i > 0)
	{
		if (int_in_arr((*a)->value, lis, lis_size))
			ft_stack_rotate(a, 'a');
		else
			ft_stack_push(a, b, 'b');
		i--;
	}
	free(arr);
	free(lis);
}

// int	ft_find_smallest(t_stack **stack_a)
// {
// 	int		i;
// 	t_stack	*temp;

// 	temp = *stack_a;
// 	i = temp->value;
// 	while (temp->next)
// 	{
// 		temp = temp->next;
// 		if (i > temp->value)
// 			i = temp->value;
// 	}
// 	return (i);
// }

// int	ft_find_mid(t_stack **stack_a)
// {
// 	int		i;
// 	int		*arr;
// 	int		len;
// 	t_stack	*temp;

// 	i = 0;
// 	temp = *stack_a;
// 	len = ft_stack_size(*stack_a);
// 	arr = (int *)malloc(sizeof(int) * len);
// 	while (temp)
// 	{
// 		arr[i] = temp->value;
// 		temp = temp->next;
// 		i++;
// 	}
// 	i = ft_bubble_sort(arr, len);
// 	free(arr);
// 	return (i);
// }

// int	ft_find_bigest(t_stack **stack_a)
// {
// 	int		i;
// 	t_stack	*temp;

// 	temp = *stack_a;
// 	i = temp->value;
// 	while (temp->next)
// 	{
// 		temp = temp->next;
// 		if (i < temp->value)
// 			i = temp->value;
// 	}
// 	return (i);
// }

// int	cheker(t_stack **stack_a, int *arr)
// {
// 	int	i;

// 	i = -1;
// 	while (i++ < 2)
// 	{
// 		if (arr[i] == (*stack_a)->value)
// 			return (1);
// 	}
// 	return (0);
// }

// void	push_not_lis(t_stack **a, t_stack **b)
// {
// 	int	num[3];
// 	int	i;
// 	int	size;

// 	i = 0;
// 	size = ft_stack_size(*a);
// 	num[0] = ft_find_smallest(a);
// 	num[1] = ft_find_mid(a);
// 	num[2] = ft_find_bigest(a);
// 	while (i < size)
// 	{
// 		if (cheker(a, num))
// 			ft_stack_rotate(a, 'a');
// 		else
// 			ft_stack_push(a, b, 'b');
// 		i++;
// 	}
// }
