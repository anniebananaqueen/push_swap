/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:35:09 by apatkano          #+#    #+#             */
/*   Updated: 2024/09/05 10:37:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/*int main(void)
{
	char    testChar = '0';

	if (ft_isdigit(testChar))
	{
		printf("%c is a digit.\n", testChar);
	}
	else
	{
		printf("%c is not a digit.\n", testcar);
	}

	return (0);
}*/