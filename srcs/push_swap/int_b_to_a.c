/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_b_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:11:19 by codespace         #+#    #+#             */
/*   Updated: 2024/09/28 15:46:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void move_b_to_a(t_stack_node **a, t_stack_node **b) {
    while (stack_len(*b) > 0) {
        t_stack_node *best_move = find_best_move_to_a(*a, *b);

        // Calculate rotations needed for stack_a and stack_b
        int rotations_a = calculate_rotations_for_a(*a, best_move->nbr);
        int rotations_b = calculate_rotations_for_b(*b, best_move);

        // Use combined rotations when possible
        if (rotations_a > 0 && rotations_b > 0) {
            while (rotations_a > 0 && rotations_b > 0) {
                rr(a, b, true);  // Add 'true' or 'false' to the function call
                rotations_a--;
                rotations_b--;
            }
        } else if (rotations_a < 0 && rotations_b < 0) {
            while (rotations_a < 0 && rotations_b < 0) {
                rrr(a, b, true);  // Add 'true' or 'false' to the function call
                rotations_a++;
                rotations_b++;
            }
        }

        // Handle remaining rotations individually
        while (rotations_a > 0) {
            ra(a, true);  // Add 'true' or 'false' to the function call
            rotations_a--;
        }
        while (rotations_a < 0) {
            rra(a, true);  // Add 'true' or 'false' to the function call
            rotations_a++;
        }
        while (rotations_b > 0) {
            rb(b, true);  // Add 'true' or 'false' to the function call
            rotations_b--;
        }
        while (rotations_b < 0) {
            rrb(b, true);  // Add 'true' or 'false' to the function call
            rotations_b++;
        }

        // Finally, push the element from b to a
        pa(a, b, true);  // Add 'true' or 'false' to the function call
    }
}

t_stack_node *find_best_move_to_a(t_stack_node *a, t_stack_node *b) {
    t_stack_node *best_move = NULL;
    t_stack_node *current = b;
    int min_total_rotations = INT_MAX;

    while (current) {
        // Calculate rotations for both stack_a and stack_b
        int rotations_a = calculate_rotations_for_a(a, current->nbr);
        int rotations_b = calculate_rotations_for_b(b, current);
        int total_rotations = abs(rotations_a) + abs(rotations_b);

        // If this move is more efficient, update the best move
        if (total_rotations < min_total_rotations) {
            min_total_rotations = total_rotations;
            best_move = current;
        }

        current = current->next;
    }

    return best_move;
}

int find_optimal_position_in_a(t_stack_node *a, int value_to_insert)
{
    t_stack_node *current = a;
    int position = 0;

    // Find the correct place to insert the value
    while (current->next)
    {
        if (current->nbr < value_to_insert && current->next->nbr > value_to_insert)
            break;
        current = current->next;
        position++;
    }
    return position;
}

void set_cheapest(t_stack_node *stack)
{
    long cheapest_value;
    t_stack_node *cheapest_node;
    t_stack_node *current;

    cheapest_value = LONG_MAX;
    cheapest_node = NULL;
    current = stack;
    while (current)
    {
        if (current->push_cost < cheapest_value)
        {
            cheapest_value = current->push_cost;
            cheapest_node = current;
        }
        current = current->next;
    }
    current = stack;
    while (current)
    {
        current->cheapest = (current == cheapest_node);
        current = current->next;
    }
}

t_stack_node *find_best_target(t_stack_node *a, int value)
{
    t_stack_node *best_target;
    t_stack_node *current;
    long best_match;

    best_target = NULL;
    current = a;
    best_match = LONG_MAX;
    while (current)
    {
        if (current->nbr > value && current->nbr < best_match)
        {
            best_match = current->nbr;
            best_target = current;
        }
        current = current->next;
    }
    if (!best_target)
        best_target = find_min(a);

    return (best_target);
}

void rotate_to_position(t_stack_node **a, int pos)
{
    int stack_size = stack_len(*a);

    if (pos <= stack_size / 2)
    {
        // Rotate forward (ra)
        while (pos-- > 0)
        {
            ra(a, true);
        }
    }
    else
    {
        // Rotate backward (rra)
        while (pos++ < stack_size)
        {
            rra(a, true);
        }
    }
}

int find_position_of_node(t_stack_node *stack, t_stack_node *node)
{
    t_stack_node *current = stack;
    int position = 0;

    // Traverse the stack to find the position of the given node
    while (current)
    {
        if (current == node)
            return position;  // Return the position when the node is found
        current = current->next;
        position++;
    }

    return -1;  // Return -1 if the node isn't found (shouldn't happen in this context)
}

int calculate_rotations_for_a(t_stack_node *a, int value) {
    int rotations = 0;
    t_stack_node *current = a;

    // Find the spot in stack_a where the element from stack_b should be inserted
    while (current->next) {
        if (current->nbr < value && current->next->nbr > value) {
            break;
        }
        rotations++;
        current = current->next;
    }

    // If no exact spot is found (edge cases like largest or smallest number)
    if (current->nbr < value && current->next == NULL) {
        rotations++;
    }

    // Adjust for reverse rotations if more than half of the stack needs to be rotated
    if (rotations > stack_len(a) / 2) {
        rotations = rotations - stack_len(a);
    }

    return rotations;
}

int calculate_rotations_for_b(t_stack_node *b, t_stack_node *target) {
    int rotations = 0;
    t_stack_node *current = b;

    // Count how many steps (rotations) it takes to bring the target node to the top of stack_b
    while (current != target) {
        rotations++;
        current = current->next;
    }

    // If more than half of stack_b needs to be rotated, rotate the other way
    if (rotations > stack_len(b) / 2) {
        rotations = rotations - stack_len(b);
    }

    return rotations;
}
