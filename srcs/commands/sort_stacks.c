/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:33:27 by codespace         #+#    #+#             */
/*   Updated: 2024/09/24 11:52:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int calculate_move_cost (t_stack_node *a, t_stack_node *b, t_stack_node *b_elem)
{
    int cost_a;
    int cost_b;

    cost_a = calculate_rotations_to_position(a, b->nbr);
    cost_b = calculate_rotations_to_top(b, b_elem);

    return (cost_a + cost_b);
}

void    rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    while ((*a != cheapest_node) && (*b != cheapest_node->target_node))
            rr(a, b, true);
}

void    rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    while ((*a != cheapest_node) && (*b != cheapest_node->target_node))
            rrr(a, b, true);
    current_index(*a);
    current_index(*b);
}

void    min_on_top(t_stack_node **a)
{
    t_stack_node *min_node;

    min_node = find_min(*a);
    
    while ((*a)->nbr != min_node->nbr)
    {
        if (min_node->above_median)
            ra(a, true);
        else
            rra(a, true);
    }
}
