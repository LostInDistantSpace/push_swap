/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:14:52 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/06 10:54:47 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;

	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	add_back(stack, first);
}

void	ra(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	rotate(&stacks->stack_b);
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
	rotate(&stacks->stack_b);
	ft_printf("rr\n");
}
