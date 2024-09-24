/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_b_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:11:19 by codespace         #+#    #+#             */
/*   Updated: 2024/09/24 14:38:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *best_move;
    t_stack_node *current;
    int min_cost;
    int cost;

    best_move = NULL;
    current = *b;
    min_cost = INT_MAX;

    while (current)
    {
        cost = calculate_move_cost(*a, *b, current);
        if (cost < min_cost)
        {
            min_cost = cost;
            best_move = current;
        }
        current = current->next;
    }
    if (best_move)
        pa(a, b, true); 
}

int cost_analysis_b(t_stack_node *a, t_stack_node *b)
{
    int cost_a;
    int cost_b;
    
    cost_a = calculate_rotations_to_position(a, b->nbr);
    cost_b = calculate_rotations_to_top(b, b->target_node);

    return (cost_a + cost_b);
}

static void set_target_b(t_stack_node *a, t_stack_node *b)
{
    t_stack_node    *current_a;
    t_stack_node    *target_node;
    long             best_match_index;

    while (b)
    {
        best_match_index = LONG_MAX;
        target_node = NULL;
        current_a = a;
        while (current_a)
        {
            if (current_a->nbr > b->nbr 
                && current_a->nbr < best_match_index)
            {
                best_match_index = current_a->nbr;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match_index == LONG_MAX)
            b->target_node = find_min(a);
        else
            b->target_node = target_node;
        b = b->next;        
    }
}

void    current_index(t_stack_node *stack)
{
    int index;
    t_stack_node    *current;

    index = 0;
    current = stack;
    while (current)
    {
        current->index = index;
        index++;
        current = current->next;
    }
}

void    init_nodes_b(t_stack_node *a, t_stack_node *b)
{
    current_index(a);
    current_index(b);
    set_target_b(a, b);
}
