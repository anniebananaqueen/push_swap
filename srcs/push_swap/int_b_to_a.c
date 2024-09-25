/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_b_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:11:19 by codespace         #+#    #+#             */
/*   Updated: 2024/09/25 12:27:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *best_move;
    int rotations_a;
    
    if (!*b)
        return;
    best_move = find_best_move_to_a(*a, *b);
    rotations_a = calculate_rotations_to_position(*a, best_move->nbr);

    if (rotations_a > 0)
    {
        while (rotations_a-- > 0)
            ra(a, true);
    }
    else
    {
        while (rotations_a++ < 0)
            rra(a, true);
    }
    pa(a, b, true);
    if (is_fully_sorted(*a))
    {
        ft_printf("Stack A is sorted after pushing from Stack B.\n");
    }
}

void    final_rotation_handling(t_stack_node **a)
{
    int rotation_count;
    int max_rotations;
    
    if (is_fully_sorted(*a))
    {
        ft_printf("Stack is already fully sorted. No further rotations needed.\n");
        return;
    }
    min_on_top(a);
    if (is_fully_sorted(*a))
    {
        ft_printf("Final stack sorted after min_on_top.\n");
        return;
    }
    rotation_count = 0;
    max_rotations = 20;
    while (!is_fully_sorted(*a) && rotation_count < max_rotations)
    {
        ra(a, true);
        rotation_count++;
        ft_printf("After rotation - Stack A: ");
        print_stack(*a);
        ft_printf("Rotation count: %d\n", rotation_count);
    }

    if (rotation_count >= max_rotations)
    {
        ft_printf("Max rotations hit. Breaking loop to avoid infinite rotation.\n");
    }
}

t_stack_node    *find_best_move_to_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *best_move;
    t_stack_node *current;
    int min_cost;

    best_move = b;
    current = b;
    min_cost = INT_MAX;
    while (current)
    {
        int cost_a = calculate_rotations_to_position(a, current->nbr);
        if (cost_a < min_cost)
        {
            min_cost = cost_a;
            best_move = current;
        }
        current = current->next;
    }
    return (best_move);
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
