/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:19:03 by codespace         #+#    #+#             */
/*   Updated: 2024/09/19 20:18:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/push_swap.h"

int calculate_median(t_stack_node *stack)
{
    int len;
    int *arr;
    int i;
    int median;
    int median_index;
    t_stack_node    *current;

    len = stack_len(stack);
    arr = malloc(sizeof(int) * len);
    if (!arr)
        return (-1);
    current = stack;
    i = 0;
    while (current)
    {
        arr[i] = current->nbr;
        current = current->next;
        i++;
    }
    quick_sort(arr, 0, len - 1);
    median_index = len / 2;
    median = arr[median_index];
    free (arr);
    return (median);
}

void    sort_three(t_stack_node **a)
{
    int first;
    int second;
    int third;

    first = (*a)->nbr;
    second = (*a)->next->nbr;
    third = (*a)->next->next->nbr;

    ft_printf("Sorting three elements: %d, %d, %d\n", first, second, third);
    if (first > second && second < third && first < third)
    {
        ft_printf("Case: sa\n");
        sa(a, true);
    }
    else if (first > second && second > third)
    {
        ft_printf("Case: sa + rra\n");
        sa(a, true);
        rra(a, true);
    }
    else if (first > second && second < third && first > third)
    {
        ft_printf("Case: ra\n");   
        ra(a, true);
    }
    else if (first < second && second > third && first < third)
    {
        ft_printf("Case: sa + ra\n");
        sa(a, true);
        ra(a, true);
    }
    else if (first < second && second > third && first > third)
    {    
        ft_printf("Case: rra\n");
        rra(a, true);
    }
}

void    sort_stacks(t_stack_node **a, t_stack_node **b)
{
    int len_a;
    int median;
    
    
    len_a = stack_len(*a);
    median = calculate_median(*a);
    while (len_a > 3 && !stack_sorted(*a))
    {
        if ((*a)->nbr < median)
        {
        pb(b, a, true);
        len_a--;
        }
        else
            ra(a, true);
    }
    sort_three(a);
    while (*b)
    {
        move_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}

