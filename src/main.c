/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:23:38 by aarponen          #+#    #+#             */
/*   Updated: 2023/09/23 17:12:55 by aarponen         ###   ########.fr       */
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

//initialize stack element
void	init_stack(t_stack *tmp, char **arg_arr, int i)
{
	tmp->nr = ft_atol(arg_arr[i]);
	tmp->pos = i + 1;
	tmp->above_median = 0;
	tmp->target = 0;
	tmp->cost = INT_MAX;
	tmp->next = NULL;
}

//create stack from argv and return pointer to the first element
t_stack	*create_stack(char **arg_arr)
{
	t_stack	*stack;
	t_stack	*tmp;
	t_stack	*last;
	int		i;

	i = 0;
	stack = NULL;
	last = NULL;
	while (arg_arr[i])
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		if (tmp == NULL)
			clear_all (&stack, &last);
		init_stack(tmp, arg_arr, i);
		if (last)
			last->next = tmp;
		last = tmp;
		if (stack == NULL)
			stack = tmp;
		i++;
	}
	i = 0;
	while (arg_arr[i])
			free(arg_arr[i++]);
	free(arg_arr);
	return (stack);
}

//create arg_array from argv
char	**create_arg_arr(int argc, char **argv)
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
	return (arg_array);
}

void   print_stack(t_stack *stack)
{
    t_stack *tmp;
    t_stack *target;

    tmp = stack;
    while (tmp)
    {
        target = tmp->target;
        if (target)
            printf("index: %d number: %d target: %d - cost: %d above: %d\n", 
					tmp->pos, tmp->nr, target->pos, tmp->cost, tmp->above_median);
        else
            printf("index: %d number: %d\n", tmp->pos, tmp->nr);
        tmp = tmp->next;
    }
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**arg_arr;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
		arg_arr = ft_split(argv[1], ' ');
	else if (argc > 2)
		arg_arr = create_arg_arr(argc, argv);
	validate_input(arg_arr);
	stack_a = create_stack(arg_arr);
	if (a_is_sorted(&stack_a) == 1)
	{
		clear_all(&stack_a, &stack_b);
		return (0);
	}
	stack_a = sorting(stack_a, stack_b);
	clear_all(&stack_a, &stack_b);
	return (0);
}
