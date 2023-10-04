/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarponen <aarponen@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:20:51 by aarponen          #+#    #+#             */
/*   Updated: 2023/10/01 11:57:04 by aarponen         ###   ########.fr       */
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

//validation
int		main(int argc, char **argv);
void	validate_input(char **arg_arr);
int		check_digits(char **arg_arr);
void	check_duplicates(t_stack **stack);
int		check_integers(char **arg_arr);
int		a_is_sorted(t_stack **stack_a);

//init and clear
char	**create_arg_arr(int argc, char **argv);
t_stack	*create_stack(char **arg_arr);
void	init_stack(t_stack *tmp, char **arg_arr, int i);
void	clear_stack(t_stack **stack, t_stack **last);
void	clear_arr(char **arr);

//operations
void	swap(t_stack **stack);
void	push(t_stack **stack_1, t_stack **stack_2);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

//sort
t_stack	*sorting(t_stack *stack_a, t_stack *stack_b);
void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_more(t_stack **stack_a, t_stack **stack_b);

//calculations
void	calc_current_pos(t_stack **stack);
void	calc_target_node(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_min(t_stack *stack);
int		nr_count(t_stack *stack);

//determine best move
void	calc_cost(t_stack **s_a, t_stack **s_b);
t_stack	*find_cheapest(t_stack **stack_b);
int		bonus(t_stack **s_a, t_stack **s_b, t_stack *a, t_stack *b);

//move to target
void	move_to_target(t_stack **stack_a, t_stack **stack_b);
void	rotate_ab(t_stack **a, t_stack **b, t_stack *cheapest, t_stack *target);
void	revrot_ab(t_stack **a, t_stack **b, t_stack *cheapest, t_stack *target);
void	rotate_a(t_stack **stack_a, t_stack *target_node);
void	rotate_b(t_stack **stack_b, t_stack *cheapest_node);
void	min_to_top(t_stack **stack_a);

// troubleshooting
// void	print_stack(t_stack *stack);
#endif
