/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:10:31 by codespace         #+#    #+#             */
/*   Updated: 2024/09/28 15:14:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int stack_len(t_stack_node *stack)
{
    int count = 0;
    while (stack)
    {
        stack = stack->next;
        count++;
    }
    return count;
}

t_stack_node    *find_last(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

bool stack_sorted(t_stack_node *a)
{
    t_stack_node *current = a;

    while (current && current->next)
    {
        if (current->nbr > current->next->nbr)
            return false;  // Not sorted in ascending order
        current = current->next;
    }

    return true;  // Sorted in ascending order
}

t_stack_node *find_min(t_stack_node *stack)
{
    t_stack_node *current = stack;
    t_stack_node *min_node = stack;

    if (!stack)
        return NULL;  // Handle empty stack

    // Traverse the stack to find the node with the smallest value
    while (current)
    {
        if (current->nbr < min_node->nbr)
            min_node = current;  // Update to the node with the smaller value
        current = current->next;
    }
    return min_node;  // Return the node containing the minimum value
}

t_stack_node *find_max(t_stack_node *stack)
{
    t_stack_node *current = stack;
    t_stack_node *max_node = stack;

    if (!stack)
        return NULL;  // Handle empty stack

    // Traverse the stack to find the node with the largest value
    while (current)
    {
        if (current->nbr > max_node->nbr)
            max_node = current;  // Update to the node with the larger value
        current = current->next;
    }
    return max_node;  // Return the node containing the maximum value
}
