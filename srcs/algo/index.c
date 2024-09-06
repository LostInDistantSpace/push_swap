/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 18:49:33 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/06 12:06:52 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tail_index(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack->index);
}

int	find_index(t_stack *stack, int target)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->index == target)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

void	assign_indexes(t_stack **stack)
{
	int		index;
	t_stack	*tmp;
	t_stack	*current;

	current = *stack;
	while (current)
	{
		tmp = *stack;
		index = 0;
		while (tmp)
		{
			if (tmp->value < current->value)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
}
