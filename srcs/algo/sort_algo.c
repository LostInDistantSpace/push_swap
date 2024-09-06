/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:26:37 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/06 12:09:19 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top_elements_to_a(t_stacks *stacks, int last_idx_a)
{
	while (stacks->stack_b->index != stacks->stack_a->index - 1)
	{
		if (stacks->stack_b->index > last_idx_a)
		{
			last_idx_a = stacks->stack_b->index;
			pa(stacks);
			ra(stacks);
		}
		else
			rb(stacks);
	}
	pa(stacks);
}

void	move_element_to_a(t_stacks *stacks)
{
	int	last_idx_a;

	last_idx_a = 0;
	if (tail_index(stacks->stack_a) < stacks->stack_a->index)
		last_idx_a = tail_index(stacks->stack_a);
	if (find_index(stacks->stack_b, (stacks->stack_a)->index - 1)
		< stacks->size_b / 2)
		move_top_elements_to_a(stacks, last_idx_a);
	else
	{
		while (stacks->stack_b->index != stacks->stack_a->index - 1)
			rrb(stacks);
		pa(stacks);
	}
}

void	partition_and_move(t_stacks *stacks, int pv1, int size)
{
	while (stacks->size_b < pv1 + size)
	{
		if (stacks->stack_a->index < pv1 + size)
			pb(stacks);
		else
			ra(stacks);
		if (stacks->size_b > 0 && (stacks->stack_b)->index
			<= pv1 + size / 2 && (stacks->stack_b)->index >= pv1)
			rb(stacks);
	}
}

void	divide_and_move(t_stacks *stacks)
{
	int	pv1;
	int	size;

	pv1 = 0;
	while (stacks->size_a > 3)
	{
		size = stacks->size_a / 3;
		if (size < 10)
			size = stacks->size_a - 3;
		partition_and_move(stacks, pv1, size);
		pv1 += size;
	}
}
