/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatkano <apatkano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:37:44 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 17:08:29 by apatkano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_hexlow(unsigned int n)
{
	char	num;
	int		i;

	i = 0;
	if (n >= 16)
	{
		i += ft_hexlow(n / 16);
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
