/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:23:38 by aarponen          #+#    #+#             */
/*   Updated: 2023/09/20 15:41:38 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//clear all allocated memory
void	clear_all(t_stack **stack, t_stack **last)
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

t_stack	*init_stack(t_stack *tmp, char **argv, int i)
{
	tmp->nr = ft_atol(argv[i]);
	tmp->pos = i + 1;
	tmp->above_median = 0;
	tmp->target = 0;
	tmp->cost = INT_MAX;
	tmp->next = NULL;
	return (tmp);
}

//create stack from argv and return pointer to the first element
t_stack	*create_stack(char **argv)
{
	t_stack	*stack;
	t_stack	*tmp;
	t_stack	*last;
	int		i;

	i = 0;
	stack = NULL;
	last = NULL;
	while (argv[i])
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (tmp == NULL)
			clear_all (&stack, &last);
		tmp = init_stack(tmp, argv, i);
		if (last)
			last->next = tmp;
		last = tmp;
		if (stack == NULL)
			stack = tmp;
		i++;
	}
	return (stack);
}

//create arg_array from argv
char	**create_argv(int argc, char **argv)
{
	char	**arg_array;
	int		i;

	i = 0;
	arg_array = (char **)malloc(sizeof(char *) * argc);
	while (i < argc - 1)
	{
		arg_array[i] = ft_strdup(argv[i + 1]);
		i++;
	}
	arg_array[i] = NULL;
	free (argv);
	return (arg_array);
}

// void   print_stack(t_stack *stack)
// {
//     t_stack *tmp;
//     t_stack *target;

//     tmp = stack;
//     while (tmp)
//     {
//         target = tmp->target;
//         if (target)
//             printf("index: %d number: %d target: %d\n", 
// 					tmp->pos, tmp->nr, target->pos);
//         else
//             printf("index: %d number: %d\n", tmp->pos, tmp->nr);
//         tmp = tmp->next;
//     }
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else if (argc > 2)
		argv = create_argv(argc, argv);
	validate_input(argv);
	stack_a = create_stack(argv);
	if (stack_a == NULL)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	// print_stack(stack_a);
	if (a_is_sorted(&stack_a) == 1)
		return (0);
	stack_b = NULL;
	sorting(stack_a, stack_b);
	// print_stack(stack_a);
	clear_all(&stack_a, &stack_b);
	return (0);
}
