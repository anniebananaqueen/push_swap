/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:11:25 by codespace         #+#    #+#             */
/*   Updated: 2024/09/29 20:07:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char	**numbers;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		numbers = split_string(argv[1], ' ');
		stack_init(&a, numbers, 2 == argc);
	}
	else
	{
		numbers = argv;
		stack_init(&a, numbers + 1, 2 == argc);
	}
	if (!sorted_stack(a))
	{
		if (get_stack_size(a) == 2)
			sa(&a, false);
		else if (get_stack_size(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
