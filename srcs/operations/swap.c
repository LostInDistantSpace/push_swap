/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:15:05 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/06 10:55:08 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*second;

	if (*stack && (*stack)->next)
	{
		second = (*stack)->next;
		(*stack)->next = second->next;
		second->next = *stack;
		*stack = second;
	}
}

void	sa(t_stacks *stacks)
{
	swap(&stacks->stack_a);
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	swap(&stacks->stack_b);
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	swap(&stacks->stack_a);
	swap(&stacks->stack_b);
	ft_printf("ss\n");
}
