/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_a_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:25:44 by codespace         #+#    #+#             */
/*   Updated: 2024/09/25 12:19:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node    *best_move;
    t_stack_node    *current;
    int min_cost;
    int cost;
    int moves_to_top_a;
    
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
    {
        moves_to_top_a = calculate_rotations_to_top(*a, best_move);
        while (moves_to_top_a-- > 0)
            ra(a, true);
        while (moves_to_top_a++ < 0)
            rra(a, true);
        pb(b, a, true);
    }
}

void    push_back_from_b(t_stack_node **a, t_stack_node **b)
{
    while (*b)
    {
        t_stack_node *best_move;
        int rotations_a;
        int rotations_b;

        best_move = find_best_move_to_a(*a, *b);
        rotations_a = calculate_rotations_to_position(*a, best_move->nbr);
        rotations_b = calculate_rotations_to_top(*b, best_move);
        if (rotations_a <= stack_len(*a) / 2)
        {
            while (rotations_a--)
                ra(a, true);
        }
        else
        {
            while (rotations_a++)
                rra(a, true);
        }
        if (rotations_b <= stack_len(*b) / 2)
        {
            while (rotations_b--)
                rb(b, true);
        }
        else
        {
            while (rotations_b++)
                rrb(b, true);
        }
        pa(a, b, true);

        ft_printf("Pushed from B to A: Stack A: ");
        print_stack(*a);
        ft_printf("Stack B: ");
        print_stack(*b);
    }
}

int cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
    int cost_a;
    int cost_b;

    cost_a = calculate_rotations_to_position(a, b->nbr);
    cost_b = calculate_rotations_to_top(b, b->target_node);
    
    return(cost_a + cost_b);
}

void    push_below_median(t_stack_node **a, t_stack_node **b, int median)
{
    int len_a;
    int pushed_to_b;
    int rotation_count;

    len_a = stack_len(*a);
    pushed_to_b = 0;
    rotation_count = len_a;
    while (pushed_to_b < len_a / 2)
    {
        if ((*a)->nbr < median)
        {
            pb(b, a, true);
            pushed_to_b++;

            ft_printf("Pushed to B: Stack A: ");
            print_stack(*a);
            ft_printf("Stack B: ");
            print_stack(*b);
        }
        else
        {
            if (!manage_rotation(a, &rotation_count, false, true))
            {
                break;
            }
        }
    }
}
