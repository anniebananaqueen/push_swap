/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:14 by codespace         #+#    #+#             */
/*   Updated: 2024/09/24 18:24:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static  void    rev_rotate(t_stack_node **stack)
{
    t_stack_node    *last;
    
    if (!*stack || !(*stack)->next)
        return;
    last = find_last(*stack);
    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    (*stack)->prev = last;
    *stack = last;
}

void    rra(t_stack_node **a, bool print)
{
    rev_rotate(a);
    if (print)
        ft_printf("rra\n");
}

void    rrb(t_stack_node **b, bool print)
{
    rev_rotate(b);
    if (print)
        ft_printf("rrb\n");
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    rev_rotate(a);
    rev_rotate(b);
    if (print)
        ft_printf("rrr\n");
}

void rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
    while ((*a != cheapest_node) || (*b != cheapest_node->target_node))
    {
        if (*a != cheapest_node && *b != cheapest_node->target_node)
        {
            rrr(a, b, true);
        }
        else if (*a != cheapest_node)
        {
            rra(a, true);
        }
        else if (*b != cheapest_node->target_node)
        {
            rrb(b, true);
        }
    }
    current_index(*a);
    current_index(*b);
}
