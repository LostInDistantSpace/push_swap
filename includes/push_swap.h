/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmouhib <bmouhib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:13:42 by bmouhib           #+#    #+#             */
/*   Updated: 2024/09/06 11:00:17 by bmouhib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H\

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <string.h>

# define RED	"\x1b[31m"
# define GRE	"\x1b[32m"
# define YEL	"\x1b[33m"
# define BLU	"\x1b[34m"
# define MAG	"\x1b[35m"
# define CYA	"\x1b[36m"
# define RES	"\x1b[0m"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	int		size_a;
	int		size_b;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_stacks;

int			stack_size(t_stack *lst);
int			ft_printf(const char *format, ...);
int			tail_index(t_stack *stack);
int			find_index(t_stack *stack, int target);
long long	ft_atoi(const char *nptr);
char		**ft_split(char const *s);
void		ft_sort(t_stacks *stacks);
void		free_split(char **split);
void		stacks_clear(t_stacks *stacks);
void		print_stack(t_stack *stack);
void		stack_clear(t_stack **stack);
void		small_sorts(t_stacks *stacks);
void		assign_indexes(t_stack **stack);
void		divide_and_move(t_stacks *stacks);
void		move_element_to_a(t_stacks *stacks);
void		add_back(t_stack **lst, t_stack *item);
void		add_front(t_stack **lst, t_stack *item);
size_t		word_count(const char *s);
t_stack		*pop(t_stack **stack);
t_stack		*stack_new(int content);
t_stack		*stack_last(t_stack *lst);
t_stacks	*init_stack(char **av, int ac);

void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);

int			stack_min(t_stack *stack);
int			stack_max(t_stack *stack);

void		push(t_stack **stack_a, t_stack **stack_b);
void		reverse_rotate(t_stack **stack);
void		rotate(t_stack **stack);
void		swap(t_stack **stack);

void		sort_three(t_stacks *stacks);
int			sort_check(t_stack *stack);

#endif