/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 19:12:31 by aarponen          #+#    #+#             */
/*   Updated: 2023/09/20 12:27:56 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swap the first two elements at the top of stack. 
//Do nothing if there is only one or no elements).
void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

//take the first element at the top of 2 and put it at the top of 1. 
//Do nothing if 2 is empty.
void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (*stack_2 == NULL)
		return ;
	tmp = *stack_2;
	*stack_2 = (*stack_2)->next;
	tmp->next = *stack_1;
	*stack_1 = tmp;
}

//shift up all elements of stack by 1. The first element becomes the last one.
void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

//shift down all elements of stack by 1. The last element becomes the first one.
void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	while (last->next->next != NULL)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}
