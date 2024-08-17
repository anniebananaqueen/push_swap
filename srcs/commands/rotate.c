/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:37:18 by codespace         #+#    #+#             */
/*   Updated: 2024/08/15 14:18:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static  void    rotate(t_stack_node **stack)
{
    t_stack_node    *last_node;
    
    if (!*stack || !(*stack)->next)
        return ;
    last_node = find_last(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}
void    ra(t_stack_node **a, bool print)
{
    rotate(a);
    if (!print)
        ft_print("ra\n");
}

void    rb(t_stack_node **b, bool print)
{
    rotate(b);
    if (!print)
        ft_print("rb\n");
}

void    rr(t_stack_node **a, t_stack_node **b, bool print)
{
    rotate(a);
    rotate(b);
    if (!print)
        ft_print("rr\n");
}

