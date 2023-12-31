/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:39:33 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/01 11:53:43 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//validate input
void	validate_input(char **arg_arr)
{
	if (check_digits(arg_arr) == 0 || check_integers(arg_arr) == 0)
	{
		write(1, "Error\n", 6);
		clear_arr(arg_arr);
		exit(1);
	}
}

//check if all arguments are digits
int	check_digits(char **arg_arr)
{
	int	i;
	int	j;

	i = 0;
	while (arg_arr[i])
	{
		j = 0; 
		if (arg_arr[i][j] == '-' || arg_arr[i][j] == '+')
			j++;
		while (arg_arr[i][j])
		{
			if (!ft_isdigit(arg_arr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

//check for duplicates
void	check_duplicates(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->nr == tmp2->nr)
			{
				write(1, "Error\n", 6);
				clear_stack(stack, &tmp);
				exit(1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

//check if all arguments are integers
int	check_integers(char **arg_arr)
{
	int		i;
	long	tmp;

	i = 0;
	while (arg_arr[i])
	{
		tmp = ft_atol(arg_arr[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

//check if stack a is sorted
int	a_is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->nr > tmp->next->nr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
