/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:11:31 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/06 12:11:20 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front(t_stack **lst, t_stack *item)
{
	if (*lst)
		item->next = *lst;
	else
		item->next = NULL;
	*lst = item;
}

void	add_back(t_stack **lst, t_stack *item)
{
	item->next = NULL;
	if (!*lst)
		*lst = item;
	else
		stack_last(*lst)->next = item;
}
