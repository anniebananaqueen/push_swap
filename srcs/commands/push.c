/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:07:54 by codespace         #+#    #+#             */
/*   Updated: 2024/09/29 17:19:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static  void    push(t_stack_node **dest, t_stack_node **src)
{
    t_stack_node    *push_node;

    if (*src == NULL)
        return ;
    push_node = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    push_node->prev = NULL;
    if (*dest == NULL)
    {
        *dest = push_node;
        push_node->next = NULL;
    }
    else
    {
        push_node->next = *dest;
        push_node->next->prev = push_node;
        *dest = push_node;
    }
}

void    pa(t_stack_node **a, t_stack_node **b, bool print)
{
    push(a, b);
    if (!print)
        ft_printf("pa\n");
}

void    pb(t_stack_node **b, t_stack_node **a, bool print)
{
    push(b, a);
    if (!print)
        ft_printf("pb\n");
}
