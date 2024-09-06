/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:24:58 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/06 12:01:57 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	large_sort(t_stacks *stacks)
{
	divide_and_move(stacks);
	small_sorts(stacks);
	while (stacks->stack_b)
	{
		move_element_to_a(stacks);
		while (tail_index(stacks->stack_a) == stacks->stack_a->index - 1)
			rra(stacks);
	}
}

void	ft_sort(t_stacks *stacks)
{
	if (sort_check(stacks->stack_a))
		return ;
	if (stacks->size_a <= 5)
		small_sorts(stacks);
	else
		large_sort(stacks);
}
