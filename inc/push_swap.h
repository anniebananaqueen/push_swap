/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:48:23 by codespace         #+#    #+#             */
/*   Updated: 2024/09/25 11:55:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> //bool flags
# include <limits.h> //MIN and MAX macros
# include "../libft/inc/libft.h"

typedef struct s_stack_node
{
	int			        nbr; //nbr to sort
	int			        index; //nbr position in the stack
    int                 push_cost; //commands in total
    bool                above_median; //to calculate 'push_cost'
    bool                cheapest; //cheapest node
    struct s_stack_node *target_node; //the target node of a node in the opposite stack
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

//Errors
int     error_syntax(char *str_n);
int     error_duplicate(t_stack_node *a, int n);
void    free_stack(t_stack_node **stack);
void    free_errors(t_stack_node **a);

//Stack
void    init_stack_a(t_stack_node **a, char **argv);
char	**split_string(const char *s, char delimiter);

//Nodes
void    init_nodes(t_stack_node *stack_to_init, t_stack_node *opposite_stack);
void    current_index(t_stack_node *stack);
void    set_cheapest(t_stack_node *stack);
void    prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name);

//Stack utils
bool    stack_sorted(t_stack_node *stack); //checking if stack is sorted
bool    manage_rotation(t_stack_node **stack, int *rotation_count, bool reverse, bool print);
bool    is_fully_sorted(t_stack_node *stack);
void    print_stack(t_stack_node *stack);
void    print_stacks(t_stack_node *a, t_stack_node *b);
int     stack_len(t_stack_node *stack);
int     calculate_median(t_stack_node *stack);
int     cost_analysis_a(t_stack_node *a, t_stack_node *b);
int     calculate_rotations_to_top(t_stack_node *stack, t_stack_node *target);
int     calculate_rotations_to_position(t_stack_node *a, int value);
int     calculate_move_cost (t_stack_node *a, t_stack_node *b, t_stack_node *b_elem);
int     find_kth_smallest(int *arr, int len, int k);
t_stack_node    *find_last(t_stack_node *stack);
t_stack_node    *find_best_move_to_a(t_stack_node *a, t_stack_node *b);
t_stack_node    *find_best_target(t_stack_node *stack, int value);
t_stack_node    *find_min(t_stack_node *stack);
t_stack_node    *find_max(t_stack_node *stack);

//Commands
void    sa(t_stack_node **a, bool print);
void    sb(t_stack_node **b, bool print);
void    ss(t_stack_node **a, t_stack_node **b, bool print);
void    ra(t_stack_node **a, bool print);
void    rb(t_stack_node **b, bool print);
void    rr(t_stack_node **a, t_stack_node **b, bool print);
void    rra(t_stack_node **a, bool print);
void    rrb(t_stack_node **b, bool print);
void    rrr(t_stack_node **a, t_stack_node **b, bool print);
void    pa(t_stack_node **a, t_stack_node **b, bool print);
void    pb(t_stack_node **b, t_stack_node **a, bool print);

//Algorithm
void    sort_three(t_stack_node **a);
void    sort_stacks(t_stack_node **a, t_stack_node **b);
void    sort_three_or_more(t_stack_node **a, t_stack_node **b);
void    finalize_sort(t_stack_node **a);
void    final_rotation_handling(t_stack_node **a);
void    move_a_to_b(t_stack_node **a, t_stack_node **b);
void    move_b_to_a(t_stack_node **a, t_stack_node **b);
void    min_on_top(t_stack_node **a);
void    push_below_median(t_stack_node **a, t_stack_node **b, int median);
void    push_back_from_b(t_stack_node **a, t_stack_node **b);

#endif
