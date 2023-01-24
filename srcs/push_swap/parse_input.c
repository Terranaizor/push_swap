/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:16:25 by nradin            #+#    #+#             */
/*   Updated: 2023/01/21 14:45:24 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	check_if_nums(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == '\f' || argv[i][j] == '\n' || argv[i][j] == '\r'
			|| argv[i][j] == '\t' || argv[i][j] == '\v' || argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '+' || argv[i][j] == '-')
			j++;
		if (!argv[i][j])
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_no_repeats(t_stack *a)
{
	t_stack	*check;

	while (a)
	{
		check = a->next;
		while (check)
		{
			if (a->value == check->value)
				return (0);
			check = check->next;
		}
		a = a->next;
	}
	return (1);
}

t_stack	*parse_stack(int argc, char *argv[])
{
	int		i;
	t_stack	*a;
	char	**args;

	a = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = ft_strstrdup(&argv[1], argc - 1);
	i = ft_strstr_len(args);
	if (check_if_nums(i, args))
	{
		while (--i >= 0)
		{
			ft_stack_add(&a, ft_stacknew(ft_atoi_error(&a, *(args + i))));
			if (!check_no_repeats(a))
				throw_error(&a);
		}
	}
	else
		throw_error(&a);
	ft_strstr_free(args);
	return (a);
}
