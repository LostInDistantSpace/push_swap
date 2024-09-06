/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:14:49 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/06 10:54:55 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*cursor;

	last = stack_last(*stack);
	cursor = *stack;
	while ((cursor)->next->value != last->value)
		cursor = cursor->next;
	cursor->next = NULL;
	add_front(stack, last);
}

void	rra(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
	reverse_rotate(&stacks->stack_b);
	ft_printf("rrr\n");
}
