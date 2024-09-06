/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:08:44 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/06 12:23:34 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	display_error(void)
{
	return (write(2, "Error !\n", 8));
}

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	if (ac <= 1)
		return (display_error());
	stacks = init_stack(av, ac);
	if (!stacks || stacks->size_a <= 0)
		return (display_error());
	if (!sort_check(stacks->stack_a))
	{
		assign_indexes(&stacks->stack_a);
		ft_sort(stacks);
	}
	stacks_clear(stacks);
	return (0);
}
