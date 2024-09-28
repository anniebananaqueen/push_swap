/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:19:41 by codespace         #+#    #+#             */
/*   Updated: 2024/09/28 15:38:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int calculate_rotations_to_position(t_stack_node *a, int value) {
    int rotations = 0;
    t_stack_node *current = a;

    while (current) {
        if (current->nbr > value && (!current->next || current->next->nbr < value)) {
            // Found the correct spot for the value
            break;
        }
        rotations++;
        current = current->next;
    }

    // If more than half the stack needs to be rotated, it might be cheaper to rotate the other way
    if (rotations > stack_len(a) / 2) {
        rotations = rotations - stack_len(a); // Rotate the other way
    }

    return rotations;
}

int calculate_rotations_to_top(t_stack_node *b, t_stack_node *target) {
    int rotations = 0;
    t_stack_node *current = b;

    while (current != target) {
        rotations++;
        current = current->next;
    }

    // If more than half the stack needs to be rotated, it might be cheaper to rotate the other way
    if (rotations > stack_len(b) / 2) {
        rotations = rotations - stack_len(b); // Rotate the other way
    }

    return rotations;
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
