/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrun.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:29:00 by marvin            #+#    #+#             */
/*   Updated: 2024/09/05 10:34:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_putnbrun(unsigned int n)
{
	char	num;
	int		i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putnbrun(n / 10);
	}
	num = '0' + n % 10;
	i += write(1, &num, 1);
	return (i);
}