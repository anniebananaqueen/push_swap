/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatkano <apatkano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 20:49:51 by apatkano          #+#    #+#             */
/*   Updated: 2024/10/12 18:04:00 by apatkano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	ft_printf_checker(const char *format, va_list args, int *j)
{
	int	i;

	i = 0;
	if (format[i] == 'c')
		*j += ft_putchar(va_arg(args, int));
	if (format[i] == 's')
		*j += ft_putstr(va_arg(args, char *));
	if (format[i] == 'p')
		*j += ft_check_null(va_arg(args, uintptr_t));
	if (format[i] == 'd' || format[i] == 'i')
		*j += ft_putnbr(va_arg(args, int));
	if (format[i] == 'u')
		*j += ft_putnbrun(va_arg(args, unsigned int));
	if (format[i] == 'x')
		*j += ft_hexlow(va_arg(args, unsigned int));
	if (format[i] == 'X')
		*j += ft_hexupp(va_arg(args, unsigned int));
	if (format[i] == '%')
		*j += write(1, "%", 1);
	i++;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_printf_checker(&format[++i], args, &j);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			j++;
			i++;
		}
	}
	va_end(args);
	return (j);
}
