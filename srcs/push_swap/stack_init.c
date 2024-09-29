/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:40:42 by codespace         #+#    #+#             */
/*   Updated: 2024/09/29 18:56:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atol(const char *str)
{
	long	nbr;
	int		negative_nbr;
	int		i;

	nbr = 0;
	negative_nbr = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negative_nbr *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * negative_nbr);
}

void	stack_init(t_stack_node **a, char **argv, bool print)
{
	long	nbr;
	int		i;

	i = 0;
    while (argv[i])
	{
        if (error_syntax(argv[i]))
            free_errors(a);
        nbr = ft_atol(argv[i]);
        if (nbr > INT_MAX || nbr < INT_MIN)
            free_errors(a);
        if (error_duplicate(*a, (int)nbr))
            free_errors(a);
        append_node(a, (int)nbr);
        ++i;
    }
    if (print)
	{
        i = 0;
        while (argv[i])
		{
            free(argv[i]);
            ++i;
        }
        free(argv);
    }
}
