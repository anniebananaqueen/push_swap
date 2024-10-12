/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatkano <apatkano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:33:27 by codespace         #+#    #+#             */
/*   Updated: 2024/10/12 16:59:59 by apatkano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

bool	sorted_stack(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

static t_stack_node	*find_max(t_stack_node *stack)
{
	int				max;
	t_stack_node	*top_node;

	if (stack == NULL)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			top_node = stack;
		}
		stack = stack->next;
	}
	return (top_node);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*top_node;

	top_node = find_max(*a);
	if (*a == top_node)
		ra(a, false);
	else if ((*a)->next == top_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_three_or_more(t_stack_node **a, t_stack_node **b)
{
	while (get_stack_size(*a) > 3)
	{
		init_nodes(*a, *b);
		final_rotation(a, find_min(*a), 'a');
		pb(b, a, false);
	}
}
