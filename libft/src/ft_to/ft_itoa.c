/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:05:17 by apatkano          #+#    #+#             */
/*   Updated: 2024/09/05 10:31:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	czechs_fills(int n, int len, char *str)
{
	if (n == -2147483648)
	{
		n = 147483648;
		str[0] = '-';
		str[1] = '2';
	}
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		str[len--] = ((n % 10) + 48);
		n = n / 10;
	}
}

static int	int_length(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = int_length(n);
	str = malloc(sizeof(char) * (int_length(n) + 1));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	czechs_fills(n, len, str);
	return (str);
}
