/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatkano <apatkano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:11:25 by codespace         #+#    #+#             */
/*   Updated: 2024/10/12 17:20:51 by apatkano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	handle_stack_init(int argc, char **argv, t_stack_node **a)
{
	char	**numbers;

	if (argc == 2)
	{
		numbers = split_string(argv[1], ' ');
		stack_init(a, numbers, 1);
	}
	else
	{
		numbers = argv + 1;
		stack_init(a, numbers, 1);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				size;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	handle_stack_init(argc, argv, &a);
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
}
