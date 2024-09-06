/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:14:50 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/05 19:38:51 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->value < min)
			min = stack->value;
	}
	return (min);
}

int	stack_max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->value > max)
			max = stack->value;
	}
	return (max);
}

int	stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*stack_last(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*pop;

	pop = *stack;
	*stack = (*stack)->next;
	pop->next = NULL;
	return (pop);
}
