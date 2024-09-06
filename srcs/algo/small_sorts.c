/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:14:21 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/06 12:01:54 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacks *stacks)
{
	if (stack_max(stacks->stack_a) == (stacks->stack_a)->value)
		ra(stacks);
	else if ((stacks->stack_a)->next->value == stack_max(stacks->stack_a))
		rra(stacks);
	if (stack_min(stacks->stack_a) != ((stacks->stack_a)->value))
		sa(stacks);
}

void	sort_four(t_stacks *stacks)
{
	int	pop_val;
	int	second;
	int	max;

	pop_val = stacks->stack_a->value;
	pb(stacks);
	sort_three(stacks);
	max = stack_max(stacks->stack_a);
	second = ((stacks->stack_a)->next)->value;
	if (pop_val < max && pop_val > second)
		rra(stacks);
	pa(stacks);
	if (pop_val > stack_min(stacks->stack_a))
	{
		if (pop_val < second)
			sa(stacks);
		else
		{
			ra(stacks);
			if (pop_val < max)
				ra(stacks);
		}
	}
}

void	special_cases(t_stacks *stacks, int pop_val, int third)
{
	if (pop_val < third)
	{
		ra(stacks);
		ra(stacks);
	}
	else
		rra(stacks);
	pa(stacks);
	if (pop_val < third)
	{
		rra(stacks);
		rra(stacks);
	}
	else
	{
		ra(stacks);
		ra(stacks);
	}
}

void	sort_five(t_stacks *stacks)
{
	int	pop_val;
	int	second;
	int	third;

	pop_val = stacks->stack_a->value;
	pb(stacks);
	sort_four(stacks);
	second = ((stacks->stack_a)->next)->value;
	third = ((stacks->stack_a)->next)->next->value;
	if (pop_val < stack_max(stacks->stack_a) && pop_val > second)
		special_cases(stacks, pop_val, third);
	else
	{
		pa(stacks);
		if (sort_check(stacks->stack_a))
			return ;
		if (pop_val < second)
			sa(stacks);
		else
			ra(stacks);
	}
}

void	small_sorts(t_stacks *stacks)
{
	if (stacks->size_a == 5)
		sort_five(stacks);
	else if (stacks->size_a == 4)
		sort_four(stacks);
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else if (stacks->size_a == 2)
	{
		if ((stacks->stack_a)->value > ((stacks->stack_a)->next)->value)
			sa(stacks);
	}
}
