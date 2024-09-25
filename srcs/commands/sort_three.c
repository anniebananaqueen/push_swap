/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:19:03 by codespace         #+#    #+#             */
/*   Updated: 2024/09/25 12:12:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/push_swap.h"

void sort_three(t_stack_node **a)
{
    int first;
    int second;
    int third;
    t_stack_node *current;

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
    ft_printf("Final sorted stack A: ");
    current = *a;
    while (current)
    {
        ft_printf("%d ", current->nbr);
        current = current->next;
    }
    ft_printf("\n");
}

void sort_three_or_more(t_stack_node **a, t_stack_node **b)
{
    while (stack_len(*a) > 3)
    {
        if ((*a)->nbr < calculate_median(*a))
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
    min_on_top(a);
}

int find_kth_smallest(int *arr, int len, int k)
{
    int i;
    int j;
    int temp;
    
    i = 0;
    j = i + 1;
    while (i <= k)
    {
        while (j < len)
        {
            if (arr[j] < arr[i])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }
    return (arr[k]);
}

int calculate_median(t_stack_node *stack)
{
    int len;
    int *arr;
    int i;
    int median;
    int median_index;
    t_stack_node *current;

    i = 0;
    len = stack_len(stack);
    if (len == 0)
        return (-1);

    arr = malloc(sizeof(int) * len);
    if (!arr)
        return (-1);

    current = stack;
    while (current)
    {
        arr[i] = current->nbr;
        current = current->next;
        i++;
    }
    median_index = len / 2;
    if (len % 2 == 0)
        median = (find_kth_smallest(arr, len, median_index - 1) + find_kth_smallest(arr, len, median_index)) / 2;
    else
        median = find_kth_smallest(arr, len, median_index);

    free(arr);
    return (median);
}

bool is_fully_sorted(t_stack_node *stack)
{
    t_stack_node *current;
    
    current = stack;
    while (current && current->next)
    {
        if (current->nbr > current->next->nbr)
            return false;
        current = current->next;
    }
    return (true);
}
