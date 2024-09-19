/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:48:23 by codespace         #+#    #+#             */
/*   Updated: 2024/09/19 20:19:04 by codespace        ###   ########.fr       */
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
int error_syntax(char *str_n);
int error_duplicate(t_stack_node *a, int n);
void    free_stack(t_stack_node **stack);
void    free_errors(t_stack_node **a);

//Stack
void    init_stack_a(t_stack_node **a, char **argv);
char	**split_string(const char *s, char delimiter);

//Nodes
void    init_nodes_a(t_stack_node *a, t_stack_node *b);
void    init_nodes_b(t_stack_node *a, t_stack_node *b);
void    current_index(t_stack_node *stack);
void    set_cheapest(t_stack_node *stack);
t_stack_node    *get_cheapest(t_stack_node *stack);
void    prep_for_push(t_stack_node **s, t_stack_node *n, char c);

//Stack utils
int stack_len(t_stack_node *stack);
t_stack_node    *find_last(t_stack_node *stack);
bool    stack_sorted(t_stack_node *stack); //checking if stack is sorted
t_stack_node    *find_min(t_stack_node *stack);
t_stack_node    *find_max(t_stack_node *stack);
void move_a_to_b(t_stack_node **a, t_stack_node **b);
void move_b_to_a(t_stack_node **a, t_stack_node **b);
void min_on_top(t_stack_node **a);
int calculate_median(t_stack_node *stack);

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

#endif
