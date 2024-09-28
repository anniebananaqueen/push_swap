/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:11:25 by codespace         #+#    #+#             */
/*   Updated: 2024/09/27 22:05:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void validate_input(t_stack_node *a)
{
    t_stack_node *current = a;

    // Traverse the stack to check for errors
    while (current)
    {
        // Check for duplicates using your 'error_duplicate' function
        if (error_duplicate(a, current->nbr))
        {
            ft_printf("Error: Duplicate values\n");
            free_stack(&a);  // Free the stack to avoid memory leaks
            exit(1);  // Exit the program if an error is found
        }

        // Add other checks if necessary (integer overflow, etc.)
        current = current->next;
    }
}

void process_input(int argc, char ***argv)
{
    if (argc == 2)
    {
        // Split the single input string into multiple arguments
        *argv = split_string((*argv)[1], ' ');
        if (!(*argv) || !(*argv)[0])
        {
            ft_printf("Error: Invalid input format\n");
            exit(1);
        }
    }

    // No need to process the input twice; ensure argv is correct
}

int main(int argc, char **argv)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;

    ft_printf("Before processing input...\n");
    process_input(argc, &argv);
    ft_printf("After processing input...\n");

    // Initialize stack A with the input
    init_stack_a(&a, argv + 1);  // Check that argv + 1 isn't duplicating input

    // Check if stack A is already sorted
    if (stack_sorted(a))
    {
        ft_printf("The stack is already sorted.\n");
        free_stack(&a);
        return 0;
    }

    // Proceed with sorting...
    sort_stacks(&a, &b);

    free_stack(&a);
    return 0;
}