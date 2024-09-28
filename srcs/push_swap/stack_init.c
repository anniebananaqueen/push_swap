/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:40:42 by codespace         #+#    #+#             */
/*   Updated: 2024/09/27 22:14:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

long ft_atol(const char *str)
{
    long result = 0;
    int sign = 1;

    // Skip any whitespace characters
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;

    // Handle optional + or - sign
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }

    // Convert the string to a long integer
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');

        // Check for overflow/underflow
        if (result * sign > LONG_MAX)
            return (LONG_MAX);
        if (result * sign < LONG_MIN)
            return (LONG_MIN);

        str++;
    }

    // Return the result multiplied by the sign (+ or -)
    return (result * sign);
}

t_stack_node *create_new_node(int value)
{
    t_stack_node *new_node;

    new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!new_node)
        return (NULL);
    
    new_node->nbr = value;
    new_node->next = NULL;
    
    return new_node;
}

void init_stack_a(t_stack_node **a, char **argv)
{
    long n;
    int i = 0;
    t_stack_node *new_node;

    while (argv[i])
    {
        ft_printf("Processing input: %s\n", argv[i]);

        // Convert input string to long
        n = ft_atol(argv[i]);

        // Validate the number
        if (n == 0 && argv[i][0] != '0')
        {
            ft_printf("Error: Invalid number\n");
            free_stack(a);  // Free the stack to avoid memory leaks
            exit(1);  // Exit the program if an error is found
        }

        // Create a new node with the integer value
        new_node = create_new_node((int)n);

        // Pass the new node and the stack pointer `a` to `init_nodes`
        init_nodes(a, new_node);

        i++;
    }
}

void init_nodes(t_stack_node **stack_to_init, t_stack_node *new_node)
{
    if (*stack_to_init == NULL)
    {
        // If the stack is empty, initialize it with the new node
        *stack_to_init = new_node;
        ft_printf("Initialized stack with first node: %d\n", new_node->nbr);
    }
    else
    {
        // If the stack is not empty, append the new node to the end of the stack
        t_stack_node *temp = *stack_to_init;
        
        // Traverse to the last node in the stack
        while (temp->next)
            temp = temp->next;
        
        // Append the new node at the end
        temp->next = new_node;
        ft_printf("Appended node with value: %d\n", new_node->nbr);
    }
}

void    prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
    while (*stack != top_node)
    {
        if (stack_name == 'a')
        {
            if (top_node->above_median)
                ra(stack, true);
            else
                rra(stack, true);
        }
        else if (stack_name == 'b')
        {
            if (top_node->above_median)
                rb(stack, true);
            else
                rrb(stack, true);
        }
    }
}
