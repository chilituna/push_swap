/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:35:50 by aarponen          #+#    #+#             */
/*   Updated: 2023/09/23 15:38:07 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//calculate current position of each node in stack
void	calc_current_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	tmp = *stack;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
	tmp = *stack;
	while (tmp)
	{
		if (tmp->pos <= ((i + 1) / 2))
			tmp->above_median = 1;
		else
			tmp->above_median = 0;
		tmp = tmp->next;
	}
}

//calculate target node in stack a above which to push node from stack b
void	calc_target_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		match_value;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_a = *stack_a;
		tmp_b->target = 0;
		match_value = INT_MAX;
		while (tmp_a)
		{
			if (tmp_b->nr < tmp_a->nr && tmp_a->nr < match_value)
			{
				tmp_b->target = tmp_a;
				match_value = tmp_a->nr;
			}
			tmp_a = tmp_a->next;
		}
		if (tmp_b->target == 0)
			tmp_b->target = find_min(*stack_a);
		tmp_b = tmp_b->next;
	}
}

//find node with lowest number in stack
t_stack	*find_min(t_stack *stack)
{
	t_stack	*tmp;
	int		min;
	t_stack	*min_node;

	tmp = stack;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->nr < min)
		{
			min = tmp->nr;
			min_node = tmp;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

//calculate how many numberr there are in stack
int	nr_count(t_stack *stack)
{
	t_stack	*tmp;
	int		count;

	tmp = stack;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
