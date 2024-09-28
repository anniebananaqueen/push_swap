/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:33:27 by codespace         #+#    #+#             */
/*   Updated: 2024/09/28 16:22:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void sort_stack_a(t_stack_node **a, t_stack_node **b) {
    // Generalized sorting logic for stack A
    while (!check_sorted(*a)) {
        move_a_to_b(a, b);  // Pushes from A to B
    }
    move_b_to_a(a, b);  // Brings elements back from B to A
    handle_final_rotation(a);  // Final alignment of elements
}

void sort_stack_b(t_stack_node **a, t_stack_node **b) {
    // Similar logic for stack B, if necessary
}

void move_a_to_b(t_stack_node **a, t_stack_node **b) {
    while (*a) {
        push_to_stack(a, b, true);  // Push from A to B
        // Consider rotation based on some logic for optimization
    }
}

void move_b_to_a(t_stack_node **a, t_stack_node **b) {
    while (*b) {
        push_to_stack(b, a, true);  // Push from B to A
        // Consider rotations or optimizations here
    }
}

void handle_final_rotation(t_stack_node **a) {
    // After sorting, ensure smallest element is at the top of A
    int min_position = find_position(*a, get_min_value(*a));
    if (min_position <= get_stack_size(*a) / 2) {
        while (min_position-- > 0)
            rotate_stack(a, true, "a");
    } else {
        while (min_position++ < get_stack_size(*a))
            reverse_rotate_stack(a, true, "a");
    }
}
