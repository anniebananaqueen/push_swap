/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:19:03 by codespace         #+#    #+#             */
/*   Updated: 2024/09/19 19:28:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/push_swap.h"

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
    
    
    len_a = stack_len(*a);
    ft_printf("Sorting stacks, length of A: %d\n", len_a);
    while (len_a > 3 && !stack_sorted(*a))
    {
        ft_printf("Pushing element from A to B\n");
        pb(b, a, true);
        len_a--;
    }
    ft_printf("Calling sort_three for remaining elements in A\n");
    sort_three(a);
    while (*b)
    {
        ft_printf("Moving element from B to A\n");
        init_nodes_b(*a, *b);
        move_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}

