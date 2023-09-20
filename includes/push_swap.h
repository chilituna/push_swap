/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:51 by aarponen          #+#    #+#             */
/*   Updated: 2023/09/20 15:19:19 by aarponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				nr;
	int				pos;
	int				above_median;
	struct s_stack	*target;
	int				cost;
	struct s_stack	*next;
}					t_stack;

int		main(int argc, char **argv);
void	validate_input(char **argv);
int		check_digits(char **argv);
int		check_duplicates(char **argv);
int		check_integers(char **argv);
int		a_is_sorted(t_stack **stack_a);

char	**create_argv(int argc, char **argv);
t_stack	*create_stack(char **argv);
t_stack	*init_stack(t_stack *tmp, char **argv, int i);

void	swap(t_stack **stack);
void	push(t_stack **stack_1, t_stack **stack_2);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

void	sorting(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_more(t_stack **stack_a, t_stack **stack_b);

void	calc_current_pos(t_stack **stack);
void	calc_target_node(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_min(t_stack *stack);
int		nr_count(t_stack *stack);

void	calc_cost(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_cheapest(t_stack **stack_b);

void	move_to_target(t_stack **stack_a, t_stack **stack_b);
void	rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest, t_stack *target);
void	revrot_ab(t_stack **a, t_stack **b, t_stack *cheapest, t_stack *target);
void	rotate_a(t_stack **stack_a, t_stack *target_node);
void	rotate_b(t_stack **stack_b, t_stack *cheapest_node);
void	min_to_top(t_stack **stack_a);

// void   print_stack(t_stack *stack);
#endif
