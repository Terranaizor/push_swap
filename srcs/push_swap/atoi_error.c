/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:50:13 by nradin            #+#    #+#             */
/*   Updated: 2023/01/21 14:45:17 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atoi_long(const char *nptr)
{
	int		i;
	int		s;
	long	num;

	i = 0;
	s = 1;
	num = 0;
	while (*(nptr + i) == '\f' || *(nptr + i) == '\n' || *(nptr + i) == '\r'
		|| *(nptr + i) == '\t' || *(nptr + i) == '\v' || *(nptr + i) == ' ')
		i++;
	if (*(nptr + i) == '+' || *(nptr + i) == '-')
	{
		if (*(nptr + i) == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit(*(nptr + i)))
	{
		num = num * 10 + (*(nptr + i) - 48);
		i++;
	}
	return ((long)(num * s));
}

int	ft_atoi_error(t_stack **a, const char *nptr)
{
	long	res;

	res = ft_atoi_long(nptr);
	if (res > INT_MAX || res < INT_MIN)
	{
		throw_error(a);
		return (0);
	}
	else
		return ((int)res);
}
