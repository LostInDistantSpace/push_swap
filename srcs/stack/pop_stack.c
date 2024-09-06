/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:47:12 by bmouhib           #+#    #+#             */
/*   Updated: 2024/08/20 15:48:45 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*pop(t_stack **stack)
{
	t_stack	*pop;

	pop = *stack;
	*stack = (*stack)->next;
	pop->next = NULL;
	return (pop);
}
