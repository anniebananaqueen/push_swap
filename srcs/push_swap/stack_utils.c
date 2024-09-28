/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:10:31 by codespace         #+#    #+#             */
/*   Updated: 2024/09/28 16:15:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void swap_top(t_stack_node **stack, bool print) {
    if (!*stack || !(*stack)->next)
        return;
    t_stack_node *first = *stack;
    t_stack_node *second = first->next;
    
    first->next = second->next;
    second->next = first;
    *stack = second;
    
    if (print)
        ft_putendl("swap");
}

void rotate_stack(t_stack_node **stack, bool print, char *stack_name) {
    if (!*stack || !(*stack)->next)
        return;
    t_stack_node *first = *stack;
    *stack = first->next;
    t_stack_node *last = *stack;
    
    while (last->next)
        last = last->next;
    
    last->next = first;
    first->next = NULL;
    
    if (print) {
        ft_putstr("r");
        ft_putendl(stack_name);
    }
}

void reverse_rotate_stack(t_stack_node **stack, bool print, char *stack_name) {
    if (!*stack || !(*stack)->next)
        return;
    t_stack_node *last = *stack;
    t_stack_node *second_last = NULL;
    
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    
    second_last->next = NULL;
    last->next = *stack;
    *stack = last;
    
    if (print) {
        ft_putstr("rr");
        ft_putendl(stack_name);
    }
}

void push_to_stack(t_stack_node **from, t_stack_node **to, bool print) {
    if (!*from)
        return;
    t_stack_node *temp = *from;
    *from = (*from)->next;
    temp->next = *to;
    *to = temp;
    
    if (print)
        ft_putendl("push");
}

int find_position(t_stack_node *stack, int value) {
    int position = 0;
    while (stack) {
        if (stack->value == value)
            return position;
        stack = stack->next;
        position++;
    }
    return -1;  // Not found
}
