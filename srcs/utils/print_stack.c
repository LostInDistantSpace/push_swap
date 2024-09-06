/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:48:04 by bmouhib           #+#    #+#             */
/*   Updated: 2024/08/19 18:31:38 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	printf(MAG "Stack :\n" RES);
	while (stack)
	{
		printf(GRE "%d\n" RES, stack->value);
		stack = stack->next;
	}
}
