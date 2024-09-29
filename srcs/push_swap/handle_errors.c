/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:08:58 by codespace         #+#    #+#             */
/*   Updated: 2024/09/29 21:20:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int error_syntax(char *str_n)
{
    if (!str_n || (*str_n != '+' && *str_n != '-' && !ft_isdigit(*str_n)))
        return (1);
    if (*str_n == '+' || *str_n == '-')
        str_n++;
    while (*str_n)
    {
        if (!ft_isdigit(*str_n))
            return(1);
        str_n++;
    }
    return (0);
}

int error_duplicate(t_stack_node *a, int n)
{
   while (a)
   {
    if (a->value == n)
        return (1);
    a = a->next;
   }
   return (0);
}

void    free_stack(t_stack_node **stack)
{
    t_stack_node    *tmp;
    t_stack_node    *current;

    if (!stack || !*stack)
        return;
    current = *stack;
    while (current)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
    *stack = NULL;
}

void    free_errors(t_stack_node **a, char **argv, bool slay)
{
    if (a && *a)
        free_stack(a);
    if (slay)
        free_split(argv);
    ft_putstr_fd("Error\n", 2);
    exit (EXIT_FAILURE);
}
