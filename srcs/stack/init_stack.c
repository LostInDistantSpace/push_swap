/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:32:03 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/05 19:19:35 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_items(char **av, int ac)
{
	int	items;
	int	count;

	items = 0;
	while (--ac > 0)
	{
		count = word_count(av[ac]);
		if (count <= 0)
			return (-1);
		items += count;
	}
	return (items);
}

t_stack	*stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	new->index = 0;
	return (new);
}

t_stack	*create_stack(char **av, int argc)
{
	int			i;
	long long	nb;
	int			count;
	char		**temp;
	t_stack		*stack;

	count = argc - 1;
	stack = NULL;
	while (count >= 1)
	{
		i = 0;
		temp = ft_split(av[count]);
		while (temp[i])
			i++;
		while (--i >= 0)
		{
			nb = ft_atoi(temp[i]);
			if (nb > INT_MAX || nb < INT_MIN)
				return (free_split(temp), stack_clear(&stack), NULL);
			add_front(&stack, stack_new(nb));
		}
		count--;
		free_split(temp);
	}
	return (stack);
}

int	check_valid(t_stack *stack)
{
	t_stack	*pointer;

	while (stack)
	{
		if (stack->value > INT_MAX || stack->value < INT_MIN)
			return (0);
		pointer = stack->next;
		while (pointer)
		{
			if (stack->value == pointer->value)
				return (0);
			pointer = pointer->next;
		}
		stack = stack->next;
	}
	return (1);
}

t_stacks	*init_stack(char **av, int ac)
{
	int			stack_size;
	t_stack		*stack;
	t_stacks	*stacks;

	stack_size = count_items(av, ac);
	if (stack_size <= 0)
		return (NULL);
	stack = create_stack(av, ac);
	if (!stack)
	{
		stack_size = -1;
		return (NULL);
	}
	if (!check_valid(stack))
	{
		stack_size = -1;
		return (stack_clear(&stack), NULL);
	}
	stacks = malloc(sizeof(t_stacks));
	stacks->size_a = stack_size;
	stacks->size_b = 0;
	stacks->stack_a = stack;
	stacks->stack_b = NULL;
	return (stacks);
}
