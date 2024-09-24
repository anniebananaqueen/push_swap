/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:11:25 by codespace         #+#    #+#             */
/*   Updated: 2024/09/24 13:21:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void process_input(int argc, char ***argv)
{
    if (argc == 2)
    {
        *argv = split_string((*argv)[1], ' ');
        if (!(*argv) || !(*argv)[0])
        {
            ft_printf("Error: Invalid input format\n");
            free(*argv);
            exit(1);
        }
    }
}

int main(int argc, char **argv)
{
    t_stack_node    *a;
    t_stack_node    *b;
    t_stack_node    *current;
    int i;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
    {
        ft_printf("No input provided\n");
        return (1);
    }
    process_input(argc, &argv);
    ft_printf("Initializing stack A...\n");
    init_stack_a(&a, argv + 1);
    current = a;
    ft_printf("Stack A: ");
    while (current)
    {
        ft_printf("%d ", current->nbr);
        current = current->next;
    }
    ft_printf("\n");
    if (!stack_sorted(a))
    {
        ft_printf("Stack is not sorted, starting sorting...\n");
        if (stack_len(a) == 2)
        {
            ft_printf("Calling sa for two elements\n");
            sa(&a, true);
        }
        else if (stack_len(a) == 3)
        {
            ft_printf("Calling sort_three\n");
            sort_three(&a);
        }
        else
        {
            ft_printf("Calling sort_stacks\n");
            sort_stacks(&a, &b);
        }
    }
        else
        {
            ft_printf("Stack is already sorted.\n");
        }
    free_stack(&a);
    if (argc == 2)
    {
        i = 0;
        while(argv[i])
        {
            free(argv[i]);
            i++;
        }
        free(argv);
    }
    return (0);
}
