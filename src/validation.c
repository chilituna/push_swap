/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:39:33 by aarponen          #+#    #+#             */
/*   Updated: 2023/09/20 15:37:50 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_input(char **argv)
{
	if (check_digits(argv) == 0 || check_duplicates(argv) == 0 
		|| check_integers(argv) == 0)
	{
		write(1, "Error\n", 6);
		free(argv);
		exit(1);
	}
}

int	check_digits(char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (argv[i])
	{
		j = 0; 
		k = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
			k++;
			if (k > 10)
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0 
				&& ft_strlen(argv[i]) == ft_strlen(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_integers(char **argv)
{
	int		i;
	long	tmp;

	i = 0;
	while (argv[i])
	{
		tmp = ft_atol(argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

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
