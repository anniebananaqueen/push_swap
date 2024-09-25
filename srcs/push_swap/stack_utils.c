/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:10:31 by codespace         #+#    #+#             */
/*   Updated: 2024/09/24 19:45:32 by codespace        ###   ########.fr       */
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

bool    stack_sorted(t_stack_node *stack)
{
    if (!stack)
        return (true);
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}

t_stack_node *find_min(t_stack_node *stack)
{
    t_stack_node *min_node = stack;
    t_stack_node *current = stack;
    
    // Traverse the stack and find the node with the smallest number
    while (current)
    {
        if (current->nbr < min_node->nbr)
        {
            min_node = current;
        }
        current = current->next;
    }
    return min_node;
}

t_stack_node *find_max(t_stack_node *stack)
{
    long max = LONG_MIN;
    t_stack_node *max_node = NULL;
    
    while (stack)
    {
        if (stack->nbr > max)
        {
            max = stack->nbr;
            max_node = stack;
        }
        stack = stack->next;
    }
    return max_node;
}
