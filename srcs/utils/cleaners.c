/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:03:00 by bmouhib           #+#    #+#             */
/*   Updated: 2024/08/20 18:25:24 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	while (i >= 0)
		free(split[i--]);
	free(split);
}

void	stack_clear(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->value = 0;
		(*stack)->next = 0;
		free(*stack);
		*stack = tmp;
	}
}

void	stacks_clear(t_stacks *stacks)
{
	stack_clear(&stacks->stack_a);
	stack_clear(&stacks->stack_b);
	free(stacks);
}
