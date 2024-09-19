/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:40:42 by codespace         #+#    #+#             */
/*   Updated: 2024/09/19 19:19:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static bool custom_atoi(const char *s, long *result)
{
    long    temp_result;
    int     sign;

    temp_result = 0;
    sign = 1;
    *result = 0;
    while (*s == ' ' || *s == '\t' || *s == '\n' || 
            *s == '\r' || *s == '\f' || *s == '\v')
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }
    if (!ft_isdigit(*s))
        return (false);
    while (ft_isdigit(*s))
    {
        temp_result = temp_result * 10 + (*s++ - '0');
        if ((temp_result * sign) > INT_MAX || (temp_result * sign) < INT_MIN)
        return (false);
    }
    if (*s != '\0')
        return (false);
    *result = temp_result * sign;
    return (true);
}

static bool append_node(t_stack_node **stack, int n)
{
    t_stack_node    *node;
    t_stack_node    *last_node;
    
    node = malloc(sizeof(t_stack_node));
    if (!node)
    {
        ft_printf("Memory allocation failed\n");
        return (false);
    }
    node->nbr = n;
    node->next = NULL;
    if (!(*stack))
    {
        *stack = node;
        node->prev = NULL;
        ft_printf("First node added to stack: %d\n", n);
    }
    else
    {
        last_node = find_last(*stack);
        last_node->next = node;
        node ->prev = last_node;
        printf("Appended node to stack: %d\n", n); 
    }
    return (true);
}

void    init_stack_a(t_stack_node **a, char **argv)
{
    long    n;
    int     i;
    
    i = 0;
    ft_printf("Initializing stack_a...\n");
    while (argv[i])
    {
        ft_printf("Processing input: %s\n", argv[i]);
        if (error_syntax(argv[i]))
            free_errors(a);
        if (!custom_atoi(argv[i], &n))
            free_errors(a);
        if (n > INT_MAX || n < INT_MIN)
            free_errors(a);
        if (error_duplicate(*a, (int)n))
            free_errors(a);
        if (!append_node(a, (int)n))
            free_errors(a);
        ft_printf("Appended %d to stack_a\n", n);
        i++;
    }
}

t_stack_node    *get_cheapest(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while (stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}

void    prep_for_push(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
    while (*stack != top_node)
    {
        if (stack_name == 'a')
        {
            if (top_node->above_median)
                ra(stack, false);
            else
                rra(stack, false);
        }
        else if (stack_name == 'b')
        {
            if (top_node->above_median)
                rb(stack, false);
            else
                rrb(stack, false);
        }
    }
}
