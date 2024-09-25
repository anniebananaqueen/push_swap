/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:30:15 by codespace         #+#    #+#             */
/*   Updated: 2024/09/24 17:48:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static  void    swap(t_stack_node **head)
{
    t_stack_node *first;
    t_stack_node *second;
    
    if (!*head || !(*head)->next)
        return;
    first = *head;
    second = (*head)->next;
    *head = second;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
}

void    sa(t_stack_node **a, bool print)
{  
    swap(a);
    if (print)
        ft_printf("sa\n");
}

void    sb(t_stack_node **b, bool print)
{
    swap(b);
    if (print)
        ft_printf("sb\n");
}

void    ss(t_stack_node **a, t_stack_node **b, bool print)
{
    swap(a);
    swap(b);
    if (print)
        ft_printf("ss\n");
}
