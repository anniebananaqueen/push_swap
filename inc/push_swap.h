/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:48:23 by codespace         #+#    #+#             */
/*   Updated: 2024/09/28 16:26:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> //bool flags
# include <limits.h> //MIN and MAX macros
# include "../libft/inc/libft.h"

typedef struct s_stack_node
{
	int			        value; // renamed from 'nbr', this is the value to be sorted
	int			        index; // index in the stack (if needed for advanced sorting or optimization)
    int                 push_cost; // commands in total, used for cost-based optimizations
    bool                above_median; // to calculate 'push_cost' (if this logic is necessary for your strategy)
    bool                cheapest; // cheapest node flag for optimization
    struct s_stack_node *target_node; // target node in the opposite stack (used for optimized pushes)
	struct s_stack_node	*next; // pointer to the next node in the stack
	struct s_stack_node	*prev; // pointer to the previous node in the stack (for doubly linked list functionality)
}	t_stack_node;

//Errors
bool check_duplicate(t_stack_node *stack);
bool check_valid_input(char *input);
void handle_error(char *error_message);
void validate_args(int argc, char **argv);
bool check_sorted(t_stack_node *stack);
//Stack
char	**split_string(const char *s, char delimiter);

//Nodes
void    set_cheapest(t_stack_node *stack);
void rotate_to_position(t_stack_node **a, int pos);
int find_optimal_position_in_a(t_stack_node *a, int value_to_insert);

//Stack utils
void swap_top(t_stack_node **stack, bool print);
void rotate_stack(t_stack_node **stack, bool print);
void reverse_rotate_stack(t_stack_node **stack, bool print);
void push_to_stack(t_stack_node **from, t_stack_node **to, bool print);
int  find_position(t_stack_node *stack, int value);
bool    is_fully_sorted(t_stack_node *stack);
void    validate_input(t_stack_node *a);
int     find_min_position(t_stack_node *stack);
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
t_stack_node   *find_min(t_stack_node *stack);
t_stack_node  *find_max(t_stack_node *stack);
int find_position_of_node(t_stack_node *stack, t_stack_node *node);

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
int calculate_rotations_for_a(t_stack_node *a, int value);
int calculate_rotations_for_b(t_stack_node *b, t_stack_node *target);

//Algorithm
void    sort_three(t_stack_node **a);
void    sort_three_or_more(t_stack_node **a, t_stack_node **b);
void    final_rotation_handling(t_stack_node **a);
void    move_a_to_b(t_stack_node **a, t_stack_node **b);
void    move_b_to_a(t_stack_node **a, t_stack_node **b);
void    push_below_median(t_stack_node **a, t_stack_node **b, int median);
void    push_back_from_b(t_stack_node **a, t_stack_node **b);

int  get_stack_size(t_stack_node *stack);
t_stack_node *get_stack_top(t_stack_node *stack);
t_stack_node *get_stack_bottom(t_stack_node *stack);
bool is_stack_empty(t_stack_node *stack);
int  get_min_value(t_stack_node *stack);
void sort_stack_a(t_stack_node **a, t_stack_node **b);
void sort_stack_b(t_stack_node **a, t_stack_node **b);


#endif
