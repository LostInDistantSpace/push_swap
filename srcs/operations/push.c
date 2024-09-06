/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:14:59 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/06 10:55:01 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b)
		add_front(stack_a, pop(stack_b));
}

void	pa(t_stacks *stacks)
{
	if (stacks->stack_b)
	{
		push(&stacks->stack_a, &stacks->stack_b);
		ft_printf("pa\n");
		stacks->size_a++;
		stacks->size_b--;
	}
}

void	pb(t_stacks *stacks)
{
	if (stacks->stack_a)
	{
		push(&stacks->stack_b, &stacks->stack_a);
		ft_printf("pb\n");
		stacks->size_b++;
		stacks->size_a--;
	}
}
