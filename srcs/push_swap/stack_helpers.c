/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:19:41 by codespace         #+#    #+#             */
/*   Updated: 2024/09/25 10:15:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int calculate_rotations_to_position(t_stack_node *a, int value)
{
    int rotations = 0;
    int total_rotations = 0;
    t_stack_node *current = a;
    t_stack_node *min_node = find_min(a);
    t_stack_node *max_node = find_max(a);

    // Count total nodes in stack A
    while (current)
    {
        total_rotations++;
        current = current->next;
    }

    // If value is smaller than min or larger than max, insert it before the min_node (circular placement)
    if (value < min_node->nbr || value > max_node->nbr)
        return calculate_rotations_to_top(a, min_node);

    // Find the correct spot for value in stack A, between nodes
    rotations = 0;
    current = a;
    while (current && current->nbr < value)
    {
        rotations++;
        current = current->next;
    }

    // If more than half of the stack needs to rotate forward, use reverse rotations
    if (rotations > total_rotations / 2)
        return total_rotations - rotations;  // Reverse rotation
    else
        return rotations;  // Forward rotation
}

int calculate_rotations_to_top(t_stack_node *stack, t_stack_node *target)
{
    int rotations = 0;
    int total_rotations = 0;
    t_stack_node *current = stack;

    while (current)
    {
        total_rotations++;
        current = current->next;
    }

    current = stack;
    while (current != target)
    {
        rotations++;
        current = current->next;
    }

    ft_printf("Total rotations: %d, Rotations to target: %d\n", total_rotations, rotations);

    if (rotations > total_rotations / 2)
    {
        ft_printf("Using reverse rotations: %d\n", total_rotations - rotations);
        return (total_rotations - rotations);
    }
    else
    {
        ft_printf("Using forward rotations: %d\n", rotations);
        return rotations;
    }
}

int calculate_move_cost(t_stack_node *a, t_stack_node *b, t_stack_node *b_elem)
{
    int cost_a;
    int cost_b;

    cost_a = calculate_rotations_to_position(a, b_elem->nbr);  
    cost_b = calculate_rotations_to_top(b, b_elem);

    return (cost_a + cost_b);
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

