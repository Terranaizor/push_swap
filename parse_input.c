/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:16:25 by nradin            #+#    #+#             */
/*   Updated: 2023/01/19 16:37:54 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_nums(int argc, char *argv[])
{
	int		i;
	int		j;
	t_stack	*a;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == 0 && )
	}
}

t_stack	*parse_stack(int argc, char *argv[])
{
	int		i;
	t_stack	*a;

	i = argc - 1;
	while (i > 0)
	{
		ft_stack_add(&a, ft_stacknew(ft_atoi(argv[i])));
		i--;
	}
}
