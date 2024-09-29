/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:48:23 by codespace         #+#    #+#             */
/*   Updated: 2024/09/29 18:36:56 by codespace        ###   ########.fr       */
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
	int                 current_pos; // current position of the value
    int			        index; // index in the stack (if needed for advanced sorting or optimization)
    int                 push_cost; // commands in total, used for cost-based optimizations
    bool                above_median; // to calculate 'push_cost' (if this logic is necessary for your strategy)
    bool                cheapest; // cheapest node flag for optimization
    struct s_stack_node *target_node; // target node in the opposite stack (used for optimized pushes)
	struct s_stack_node	*next; // pointer to the next node in the stack
	struct s_stack_node	*prev; // pointer to the previous node in the stack (for doubly linked list functionality)
}	                t_stack_node;

// Errors
int error_syntax(char *str_n);
int error_duplicate(t_stack_node *a, int n);
void    free_stack(t_stack_node **stack);
void    free_errors(t_stack_node **a);

// Commands Directory
void    pa(t_stack_node **a, t_stack_node **b, bool print);
void    pb(t_stack_node **b, t_stack_node **a, bool print);
void    ra(t_stack_node **a, bool print);
void    rb(t_stack_node **b, bool print);
void    rr(t_stack_node **a, t_stack_node **b, bool print);
void    rra(t_stack_node **a, bool print);
void    rrb(t_stack_node **b, bool print);
void    rrr(t_stack_node **a, t_stack_node **b, bool print);
void    sa(t_stack_node **a, bool print);
void    sb(t_stack_node **b, bool print);
void    ss(t_stack_node **a, t_stack_node **b, bool print);
void	final_rotation(t_stack_node **stack, t_stack_node *top_node, char stack_name);
void	push_swap(t_stack_node **a, t_stack_node **b);
bool    sorted_stack(t_stack_node *stack);
void    sort_three(t_stack_node **a);
void    sort_three_or_more(t_stack_node **a, t_stack_node **b);

//Push_swap Directory
char	**split_string(const char *s, char delimiter);
void	stack_init(t_stack_node **a, char **argv, bool print);
t_stack_node	*find_last_node(t_stack_node *head);
void	append_node(t_stack_node **stack, int nbr);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*return_cheapest(t_stack_node *stack);
int	get_stack_size(t_stack_node *stack);
void	set_current_pos(t_stack_node *stack);
void	set_price(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *b);
void	init_nodes(t_stack_node *a, t_stack_node *b);


#endif
