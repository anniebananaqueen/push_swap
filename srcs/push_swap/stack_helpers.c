/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:19:41 by codespace         #+#    #+#             */
/*   Updated: 2024/09/28 16:23:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int get_stack_size(t_stack_node *stack) {
    int size = 0;
    while (stack) {
        size++;
        stack = stack->next;
    }
    return size;
}

t_stack_node *get_stack_top(t_stack_node *stack) {
    return stack;
}

t_stack_node *get_stack_bottom(t_stack_node *stack) {
    while (stack && stack->next)
        stack = stack->next;
    return stack;
}

bool is_stack_empty(t_stack_node *stack) {
    return stack == NULL;
}

int get_min_value(t_stack_node *stack) {
    int min = stack->value;
    while (stack) {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return min;
}
