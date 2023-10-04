/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:23:38 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/01 12:59:43 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//clear stack
void	clear_stack(t_stack **stack, t_stack **last)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*last = NULL;
	exit(1);
}

//clear arr
void	clear_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

// FOR TROUBLESHOOTING:
// void   print_stack(t_stack *stack)
// {
//     t_stack *tmp;
//     t_stack *target;

//     tmp = stack;
//     while (tmp)
//     {
//         target = tmp->target;
//         if (target)
//             printf("number: %d target: %d - cost: %d above: %d\n", 
// 					tmp->nr, target->pos, tmp->cost, tmp->above_median);
//         else
//             printf("index: %d number: %d\n", tmp->pos, tmp->nr);
//         tmp = tmp->next;
//     }
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arg_arr;

	stack_a = NULL;
	stack_b = NULL;
	arg_arr = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
		arg_arr = ft_split(argv[1], ' ');
	else if (argc > 2)
		arg_arr = create_arg_arr(argc, argv);
	validate_input(arg_arr);
	stack_a = create_stack(arg_arr);
	check_duplicates(&stack_a);
	if (a_is_sorted(&stack_a) == 1)
	{
		clear_stack(&stack_a, &stack_b);
		return (0);
	}
	stack_a = sorting(stack_a, stack_b);
	clear_stack(&stack_a, &stack_b);
	return (0);
}
