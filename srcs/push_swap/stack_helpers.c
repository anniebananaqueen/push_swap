/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:19:41 by codespace         #+#    #+#             */
/*   Updated: 2024/09/24 12:09:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int calculate_rotations_to_position(t_stack_node *a, int value)
{
    int rotations;
    t_stack_node *current;
    t_stack_node    *min_node;
    
    rotations = 0;
    current = a;
    min_node = find_min(a);

    if (value < min_node->nbr)
        return (calculate_rotations_to_top(min_node));
    while (current && current->nbr < value)
    {
        rotations++;
        current = current->next;
    }
    return (rotations);
}

int calculate_rotations_to_top(t_stack_node *stack, t_stack_node *target)
{
    int rotations;
    int total_rotations;
    t_stack_node    *current;
    
    rotations = 0;
    total_rotations = 0;
    current = stack;

    while (current)
    {
        total_rotations++;
        current = current->next;
    }
    current = stack;
    while (current != target)
    {
        rotations++;
        current = current->next;
    }
    if (rotations > total_rotations / 2)
        return (total_rotations - rotations);
    
    return (rotations);
}

void    quick_sort(int *arr, int low, int high)
{
    int pivot;

    pivot = partition(arr, low, high);
    if (low < high)
    {
        quick_sort(arr, low, pivot - 1);
        quick_sort(arr, pivot + 1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot;
    int i;
    int j;
    int temp;

    pivot = arr[high];
    i = (low - 1);
    j = low;
    while (j <= high - 1)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}