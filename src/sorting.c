/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:42:14 by aarponen          #+#    #+#             */
/*   Updated: 2023/09/20 15:19:08 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->nr > (*stack_a)->next->nr)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
}

void	sort_three(t_stack **a)
{
	while (a_is_sorted(a) == 0)
	{
		if (((*a)->nr > (*a)->next->next->nr) && (*a)->nr < (*a)->next->nr)
		{
			reverse_rotate(a);
			write(1, "rra\n", 4);
		}
		else if (((*a)->nr > (*a)->next->next->nr) && (*a)->nr > (*a)->next->nr)
		{
			rotate(a);
			write(1, "ra\n", 3);
		}
		else
		{
			swap(a);
			write(1, "sa\n", 3);
		}
	}
}

void	sort_more(t_stack **stack_a, t_stack **stack_b)
{
	while (nr_count(*stack_a) > 3)
	{
		push(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
	if (nr_count(*stack_a) != 3)
	{
		write(1, "oh\n", 3);
		return ;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		calc_current_pos(stack_a);
		calc_current_pos(stack_b);
		calc_target_node(stack_a, stack_b);
		calc_cost(stack_a, stack_b);
		// write (1, "Stack A:\n", 9);
		// print_stack(*stack_a);
		// write (1, "Stack B:\n", 9);
		// print_stack (*stack_b);
		move_to_target(stack_a, stack_b);
	}
	// print_stack(*stack_a);
	calc_current_pos(stack_a);
	min_to_top(stack_a);
}

void	min_to_top(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = find_min(*stack_a);
	rotate_a(stack_a, tmp);
}

void	sorting(t_stack *stack_a, t_stack *stack_b)
{
	if (nr_count(stack_a) == 1)
		return ;
	if (nr_count(stack_a) == 2)
		sort_two(&stack_a);
	else if (nr_count(stack_a) == 3)
		sort_three(&stack_a);
	else
		sort_more(&stack_a, &stack_b);
}
