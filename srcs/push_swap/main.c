/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradin <nradin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:59:03 by nradin            #+#    #+#             */
/*   Updated: 2023/01/30 19:39:58 by nradin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = parse_stack(argc, argv);
	if (!ft_stack_is_sorted(a))
		ft_push_swap(&a);
	ft_stack_clear(&a);
	return (0);
}
