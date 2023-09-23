/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:20:57 by aarponen          #+#    #+#             */
/*   Updated: 2023/09/23 15:32:15 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//calculate cost of moving a node to the top of stack a
void	calc_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	t_stack	*a;

	b = *stack_b;
	a = *stack_a;
	while (b)
	{
		a = *stack_a;
		while (a)
		{
			if (b->target == a && a->above_median == 1 && b->above_median == 1)
				b->cost = (a->pos - 1) + (b->pos - 1) - move_both_bonus(a, b);
			if (b->target == a && a->above_median == 0 && b->above_median == 0)
				b->cost = ((nr_count(*stack_a) + 1) - a->pos) 
					+ ((nr_count(*stack_b) + 1) - b->pos) - move_both_bonus(a, b);
			if (b->target == a && a->above_median == 1 && b->above_median == 0)
				b->cost = a->pos - 1 + (nr_count(*stack_b) + 1) - b->pos;
			if (b->target == a && a->above_median == 0 && b->above_median == 1)
				b->cost = b->pos - 1 + (nr_count(*stack_a) + 1) - a->pos;
			a = a->next;
		}
		b = b->next;
	}
}

//find cheapest node to move to the top of stack a
t_stack	*find_cheapest(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*cheapest_node;
	int		cheapest;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (tmp->cost < cheapest)
		{
			cheapest = tmp->cost;
			cheapest_node = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest_node);
}

//calculate bonus for rotating both stacks at the same time
int	move_both_bonus(t_stack *a, t_stack *b)
{
	int		bonus;
	int		min_pos;

	bonus = 0;
	min_pos = 0;
	if (a->above_median == 1)
	{
		min_pos = a->pos;
		if (b->pos < min_pos)
			min_pos = b->pos;
		bonus = min_pos - 1;
	}
	else
	{
		bonus = nr_count(a) - a->pos + 1;
		if (nr_count(b) - b->pos + 1 < min_pos)
			bonus = nr_count(b) - b->pos + 1;
	}
	return (bonus);
}