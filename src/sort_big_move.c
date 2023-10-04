/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:46:22 by aarponen          #+#    #+#             */
/*   Updated: 2023/09/24 14:18:39 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//move cheapest node to the top of stack a
void	move_to_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	t_stack	*target;

	cheapest = find_cheapest(stack_b);
	target = cheapest->target;
	if (cheapest->above_median == 1 && target->above_median == 1)
		rotate_ab(stack_a, stack_b, cheapest, target);
	else if (cheapest->above_median == 0 && target->above_median == 0)
		revrot_ab(stack_a, stack_b, cheapest, target);
	calc_current_pos(stack_a);
	rotate_a(stack_a, target);
	calc_current_pos(stack_b);
	rotate_b(stack_b, cheapest);
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

//rotate both stacks until cheapest node is on top of stack b 
//or target node is on top of stack a
void	rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest, t_stack *target)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a != target && tmp_b != cheapest && tmp_a && tmp_b)
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
		tmp_a = *a;
		tmp_b = *b;
	}
}

//reverse rotate both stacks until cheapest node is on top of stack b 
//or target node is on top of stack a
void	revrot_ab(t_stack **a, t_stack **b, t_stack *cheapest, t_stack *target)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	while (tmp_a != target && tmp_b != cheapest && tmp_a && tmp_b)
	{
		reverse_rotate(a);
		reverse_rotate(b);
		write(1, "rrr\n", 4);
		tmp_a = *a;
		tmp_b = *b;
	}
}

//rotate stack a until target node is on top
void	rotate_a(t_stack **stack_a, t_stack *target_node)
{
	if (target_node->above_median == 1)
	{
		while (*stack_a != target_node)
		{
			rotate(stack_a);
			write(1, "ra\n", 3);
		}
	}
	else
	{
		while (*stack_a != target_node)
		{
			reverse_rotate(stack_a);
			write(1, "rra\n", 4);
		}
	}
}

//rotate stack b until cheapest node is on top
void	rotate_b(t_stack **stack_b, t_stack *cheapest_node)
{
	if (cheapest_node->above_median == 1)
	{
		while (*stack_b != cheapest_node)
		{
			rotate(stack_b);
			write(1, "rb\n", 3);
		}
	}
	else
	{
		while (*stack_b != cheapest_node)
		{
			reverse_rotate(stack_b);
			write(1, "rrb\n", 4);
		}
	}
}
