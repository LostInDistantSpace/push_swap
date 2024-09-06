/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 15:20:37 by bmouhib           #+#    #+#             */
/*   Updated: 2024/08/20 18:03:46 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char c)
{
	if (c == '+' || c == '-' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

size_t	word_count(const char *s)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != 32 && !is_valid(s[i]))
			return (-1);
		if (s[i] != 32 && (i == 0 || s[i - 1] == 32))
			words++;
		i++;
	}
	return (words);
}
