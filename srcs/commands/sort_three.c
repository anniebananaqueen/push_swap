/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:19:03 by codespace         #+#    #+#             */
/*   Updated: 2024/08/15 14:30:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void    sort_three(t_stack_node **a)
{
    t_stack_node    *biggest_node;
    
    biggest_node = find_max(*a);
    if (biggest_node == *a)
        ra(a, false);
    else if ((*a)->next == biggest_node)
        rra(a, false);
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a, false);
}
