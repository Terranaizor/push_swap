/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:29:10 by nradin            #+#    #+#             */
/*   Updated: 2023/01/21 14:45:19 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	throw_error(t_stack **a)
{
	ft_putstr_fd("Error\n", 2);
	ft_stack_clear(a);
	exit(0);
}

size_t	ft_strstr_len(char **str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	**ft_strstrdup(char **str, int size)
{
	char	**res;
	int		i;

	res = (char **)ft_calloc(sizeof(char *), size + 1);
	i = 0;
	while (i < size)
	{
		res[i] = ft_strdup(str[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_strstr_free(char **str)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strstr_len(str);
	while (i < size)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
