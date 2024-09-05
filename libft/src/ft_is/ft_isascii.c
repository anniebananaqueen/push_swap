/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:53:28 by apatkano          #+#    #+#             */
/*   Updated: 2024/09/05 10:37:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

/*int	main(void)
{
	char	testChar;

	testChar = 'a';
	if (ft_isascii(testChar))
	{
		printf("%c is in an ascii chart.\n", testChar);
	}
	else
	{
		printf("%c is not in an ascii chart.\n", testChar);
	}
	return (0);
}*/
