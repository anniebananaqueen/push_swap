/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:52:26 by marvin            #+#    #+#             */
/*   Updated: 2024/07/04 16:48:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_ptr(uintptr_t n)
{
	char	num;
	int		i;

	i = 0;
	if (n >= 16)
	{
		i += ft_ptr(n / 16);
	}
	if (n % 16 <= 9)
	{
		num = '0' + n % 16;
		i += write(1, &num, 1);
	}
	else if (n % 16 < 16)
	{
		num = 'a' + (n % 16 - 10);
		i += write(1, &num, 1);
	}
	return (i);
}

int	check_null(uintptr_t n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i += ft_putstr("0x");
	i += ft_ptr(n);
	return (i);
}