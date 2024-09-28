/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:40:42 by codespace         #+#    #+#             */
/*   Updated: 2024/09/28 16:24:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack_node *create_node(int value) {
    t_stack_node *new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!new_node)
        handle_error("Error: Memory allocation failed");
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

t_stack_node *init_stack(int argc, char **argv) {
    t_stack_node *stack = NULL;
    for (int i = 1; i < argc; i++) {
        int value = ft_atoi(argv[i]);
        if (check_duplicate(stack))
            handle_error("Error: Duplicate values found");
        push_to_stack(&stack, create_node(value), false);
    }
    return stack;
}
