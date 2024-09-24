/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_a_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:25:44 by codespace         #+#    #+#             */
/*   Updated: 2024/09/24 12:15:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *best_move;
    t_stack_node    *current;
    int min_cost;
    int cost;
    
    best_move = NULL;
    min_cost = INT_MAX;
    current = *a;
    while (current)
    {
        cost = cost_analysis_a(*a, *b);
        if (cost < min_cost)
        {
            min_cost = cost;
            best_move = current;
        }
        current = current->next;
    }
    if (best_move)
        pb(b, a, true);
}

int cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
    int cost_a;
    int cost_b;

    cost_a = calculate_rotations_to_position(a, b->nbr);
    cost_b = calculate_rotations_to_top(b, b_elem);
    
    return(cost_a + cost_b);
}

void    set_target_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node    *target_node;

    while (a)
    {
        target_node = find_best_target(b, a->nbr);
        a->target_node = target_node;
        a = a->next;
    }
}

void    set_cheapest(t_stack_node *stack)
{
    long             cheapest_value;
    t_stack_node    *cheapest_node;

    cheapest_value = LONG_MAX;
    cheapest_node = NULL;
    while (stack)
    {
        if (stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;
            cheapest_node = stack;
        }
        stack = stack->next;
    }
    if (cheapest_node)
        cheapest_node->cheapest = true;
}

void    init_nodes_a(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_analysis_a(a, b);
    set_cheapest(a);
}
