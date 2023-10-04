/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:25:56 by aarponen          #+#    #+#             */
/*   Updated: 2023/09/24 14:37:53 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			clear_stack (&stack, &last);
		init_stack(tmp, arg_arr, i);
		if (last)
			last->next = tmp;
		last = tmp;
		if (stack == NULL)
			stack = tmp;
		i++;
	}
	clear_arr(arg_arr);
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
