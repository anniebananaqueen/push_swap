/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:37:18 by codespace         #+#    #+#             */
/*   Updated: 2024/08/27 15:39:38 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void rotate(t_stack_node **stack)
{
    t_stack_node    *first_node;
    t_stack_node    *last_node;
    
    if (!*stack || !(*stack)->next)
        return;
    first_node = *stack;
    last_node = find_last(*stack);
    
    *stack = first_node->next;
    (*stack)->prev = NULL;
    last_node->next = first_node;
    first_node->next = NULL;
    first_node->prev = last_node;
}

void    ra(t_stack_node **a, bool print)
{
    rotate(a);
    if (print)
        ft_printf("ra\n");
}

void    rb(t_stack_node **b, bool print)
{
    rotate(b);
    if (print)
        ft_printf("rb\n");
}

void    rr(t_stack_node **a, t_stack_node **b, bool print)
{
    rotate(a);
    rotate(b);
    if (print)
        ft_printf("rr\n");
}
