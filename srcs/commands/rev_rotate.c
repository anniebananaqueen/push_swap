/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:13:14 by codespace         #+#    #+#             */
/*   Updated: 2024/09/29 17:13:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static  void    reverse_rotate(t_stack_node **stack)
{
    t_stack_node    *last;
    int length;

    length = get_stack_size(*stack);
    if (*stack == NULL || stack == NULL || length == 1)
        return ;
    last = find_last_node(*stack);
    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    *stack = last;
    last->next->prev = last;
}

void    rra(t_stack_node **a, bool print)
{
    reverse_rotate(a);
    if (!print)
        ft_printf("rra\n");
}

void    rrb(t_stack_node **b, bool print)
{
    reverse_rotate(b);
    if (!print)
        ft_printf("rrb\n");
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print)
{
    reverse_rotate(a);
    reverse_rotate(b);
    if (!print)
        ft_printf("rr\n");
}
