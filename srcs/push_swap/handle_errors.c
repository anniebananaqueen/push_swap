/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:08:58 by codespace         #+#    #+#             */
/*   Updated: 2024/09/28 16:17:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

bool check_duplicate(t_stack_node *stack) {
    t_stack_node *ptr1 = stack;
    while (ptr1 && ptr1->next) {
        t_stack_node *ptr2 = ptr1->next;
        while (ptr2) {
            if (ptr1->value == ptr2->value)
                return true;  // Duplicate found
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return false;
}

bool check_valid_input(char *input) {
    int i = 0;
    if (input[i] == '-' || input[i] == '+') i++;
    while (input[i]) {
        if (!ft_isdigit(input[i]))
            return false;
        i++;
    }
    return true;
}

void handle_error(char *error_message) {
    ft_putendl(error_message);
    exit(EXIT_FAILURE);
}

void validate_args(int argc, char **argv) {
    for (int i = 1; i < argc; i++) {
        if (!check_valid_input(argv[i])) {
            handle_error("Error: Invalid input");
        }
    }
}

bool check_sorted(t_stack_node *stack) {
    if (!stack || !stack->next)
        return true;  // Single element or empty stack is considered sorted
    
    while (stack && stack->next) {
        if (stack->value > stack->next->value)
            return false;  // Not sorted
        stack = stack->next;
    }
    return true;  // Stack is sorted
}
