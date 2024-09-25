/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:33:27 by codespace         #+#    #+#             */
/*   Updated: 2024/09/25 12:05:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void sort_stacks(t_stack_node **a, t_stack_node **b)
{
    while (stack_len(*a) > 3)
    {
        if ((*a)->nbr <= calculate_median(*a))
        {
            pb(b, a, true);
        }
        else
        {
            ra(a, true);
        }
    }
    sort_three(a);
    while (*b)
    {
        move_b_to_a(a, b);
    }
    final_rotation_handling(a);
}

void min_on_top(t_stack_node **a)
{
    int len;
    int rotations;
    t_stack_node    *min_node;
    t_stack_node    *current;
    
    if (stack_sorted(*a)) 
    {
        ft_printf("Stack is already sorted. No need for min_on_top.\n");
        return ;
    }

    min_node = find_min(*a);
    len = stack_len(*a);
    rotations = 0;
    current = *a;
    while (current != min_node)
    {
        rotations++;
        current = current->next;
    }
    ft_printf("Minimum value: %d, Rotations needed: %d\n", min_node->nbr, rotations);
    if (rotations > len / 2)
    {
        ft_printf("Using reverse rotations (rra)\n");
        while (*a != min_node)
        {
            rra(a, true);
            ft_printf("Stack A after rra: ");
            print_stack(*a);
        }
    }
    else
    {
        ft_printf("Using forward rotations (ra)\n");
        while (*a != min_node)
        {
            ra(a, true);
            ft_printf("Stack A after ra: ");
            print_stack(*a);
        }
    }
}

bool manage_rotation(t_stack_node **stack, int *rotation_count, bool reverse, bool print)
{
    if (*rotation_count <= 0)
    {
        ft_printf("Rotation limit reached.\n");
        return false;
    }
    if (!reverse)
    {
        ra(stack, print);
    }
    else
    {
        rra(stack, print);
    }

    (*rotation_count)--;
    return (true);
}

void finalize_sort(t_stack_node **a)
{
    min_on_top(a);

    ft_printf("Final sorted Stack A: ");
    print_stack(*a);
}

void print_stacks(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *current;

    ft_printf("Stack A: ");
    current = a;
    while (current)
    {
        ft_printf("%d ", current->nbr);
        current = current->next;
    }
    ft_printf("\n");

    ft_printf("Stack B: ");
    current = b;
    while (current)
    {
        ft_printf("%d ", current->nbr);
        current = current->next;
    }
    ft_printf("\n\n");
}

void print_stack(t_stack_node *stack)
{
    t_stack_node *current;
    
    current = stack;
    while (current)
    {
        ft_printf("%d ", current->nbr);
        current = current->next;
    }
    ft_printf("\n");
}
