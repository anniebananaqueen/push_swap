/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:48:23 by codespace         #+#    #+#             */
/*   Updated: 2024/10/13 11:36:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"
# include <limits.h>  //MIN and MAX macros
# include <stdbool.h> //bool flags

typedef struct s_stack_node
{
	int					value;
	int					current_pos;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// Errors
int						error_syntax(char *str_n);
int						error_duplicate(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **a, char **argv, bool slay);

// Commands Directory
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					final_rotation(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
void					push_swap(t_stack_node **a, t_stack_node **b);
bool					sorted_stack(t_stack_node *stack);
void					sort_three(t_stack_node **a);
void					sort_three_or_more(t_stack_node **a, t_stack_node **b);

// Push_swap Directory
char					**split_string(char *s, char delimiter);
void					free_split(char **result);
void					stack_init(t_stack_node **a, char **argv, bool init);
t_stack_node			*find_last_node(t_stack_node *head);
void					append_node(t_stack_node **stack, int nbr);
t_stack_node			*find_min(t_stack_node *stack);
t_stack_node			*return_cheapest(t_stack_node *stack);
int						get_stack_size(t_stack_node *stack);
void					set_current_pos(t_stack_node *stack);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *b);
void					init_nodes(t_stack_node *a, t_stack_node *b);

#endif
