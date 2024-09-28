/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:33:27 by codespace         #+#    #+#             */
/*   Updated: 2024/09/28 15:17:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void sort_stacks(t_stack_node **a, t_stack_node **b)
{
    int median;

    median = calculate_median(*a);

    // Early exit if the stack is already sorted
    if (stack_sorted(*a))
    {
        ft_printf("Stack is already sorted. Exiting early.\n");
        return;
    }

    // Step 1: Push elements from `a` to `b` based on the median
    while (stack_len(*a) > 3)
    {
        ft_printf("Checking stack before operation. Top value: %d, Median: %d\n", (*a)->nbr, median);

        if ((*a)->nbr <= median)
        {
            pb(b, a, true);  // Push to stack `b`
            median = calculate_median(*a);  // Recalculate the median after modifying the stack
        }
        else
        {
            ra(a, true);  // Rotate stack `a`
        }

        // Check if stack `a` is already sorted during rotation
        if (stack_sorted(*a))
        {
            ft_printf("Stack is sorted during process. Exiting rotation loop.\n");
            break;
        }
    }

    // Step 2: Sort the remaining 3 elements in `a`
    sort_three(a);  // Sort the remaining 3 elements in stack `a`

    // Step 3: Push elements back from `b` to `a`
    while (*b)
    {
        move_b_to_a(a, b);

        // Step 4: Check if the stack needs to be aligned
        if (!stack_sorted(*a))
        {
            ft_printf("Stack A is not yet sorted after the move. Aligning...\n");
            final_rotation_handling(a);  // Align stack `a` after each `pa`
        }
        else
        {
            ft_printf("Stack A is sorted after the move.\n");
            break;  // Exit the loop once the stack is sorted
        }
    }

    // Step 5: Final alignment if needed
    final_rotation_handling(a);  // Ensure the stack is correctly aligned after all moves
}

void min_on_top(t_stack_node **a)
{
    t_stack_node *min_node = find_min(*a);  // Get the node containing the minimum value
    int min_pos = find_position_of_node(*a, min_node);  // Assuming a helper function to find position

    int stack_size = stack_len(*a);

    if (min_pos <= stack_size / 2)
    {
        // Rotate forward (ra) to bring the minimum node to the top
        while (min_pos-- > 0)
        {
            ra(a, true);
        }
    }
    else
    {
        // Reverse rotate (rra) to bring the minimum node to the top
        while (min_pos++ < stack_size)
        {
            rra(a, true);
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
