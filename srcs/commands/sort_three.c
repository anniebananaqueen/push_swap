/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:19:03 by codespace         #+#    #+#             */
/*   Updated: 2024/08/27 17:02:25 by codespace        ###   ########.fr       */
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

    if (first > second && second < third && first < third)
        sa(a, true);
    else if (first > second && second > third)
    {
        sa(a, true);
        rra(a, true);
    }
    else if (first > second && second < third && first > third)
        ra(a, true);
    else if (first < second && second > third && first < third)
    {
        sa(a, true);
        ra(a, true);
    }
    else if (first < second && second > third && first > third)
        rra(a, true);
}

void    sort_stacks(t_stack_node **a, t_stack_node **b)
{
    int len_a;
    
    len_a = stack_len(*a);
    while (len_a > 3 && !stack_sorted(*a))
    {
        pb(b, a, true);
        len_a--;
    }
    sort_three(a);
    while (*b)
    {
        init_nodes_b(*a, *b);
        move_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}

