/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatkano <apatkano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:36:38 by apatkano          #+#    #+#             */
/*   Updated: 2024/10/12 17:08:21 by apatkano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_hexupp(unsigned int n)
{
	char	num;
	int		i;

	i = 0;
	if (n >= 16)
	{
		i += ft_hexupp(n / 16);
	}
	if (n % 16 <= 9)
	{
		num = '0' + n % 16;
		i += write(1, &num, 1);
	}
	else if (n % 16 < 16)
	{
		num = 'A' + (n % 16 - 10);
		i += write(1, &num, 1);
	}
	return (i);
}
