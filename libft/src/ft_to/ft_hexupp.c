/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:36:38 by apatkano          #+#    #+#             */
/*   Updated: 2024/09/05 10:31:51 by codespace        ###   ########.fr       */
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