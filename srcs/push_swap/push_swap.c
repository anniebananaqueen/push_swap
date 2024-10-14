/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:11:25 by codespace         #+#    #+#             */
/*   Updated: 2024/10/13 11:32:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void handle_stack_init(int argc, char **argv, t_stack_node **a, bool *is_dynamic)
{
    char **numbers;

    if (argc == 2)
    {
        numbers = split_string(argv[1], ' ');
        *is_dynamic = true; 
        stack_init(a, numbers, 1);
    }
    else
    {
        numbers = argv + 1;
        *is_dynamic = false;
        stack_init(a, numbers, 0);
    }
}

int main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;
    int size;
    bool is_dynamic;

    a = NULL;
    b = NULL;
	is_dynamic = false;
    if (argc < 2 || (argc == 2 && !argv[1][0]))
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    handle_stack_init(argc, argv, &a, &is_dynamic);
    if (!sorted_stack(a))
    {
        size = get_stack_size(a);
        if (size == 2)
            sa(&a, false);
        else if (size == 3)
            sort_three(&a);
        else
            push_swap(&a, &b);
    }
    free_stack(&a);
    if (is_dynamic)
        free_split(argv);
}
