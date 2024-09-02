/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:01:24 by apatkano          #+#    #+#             */
/*   Updated: 2024/08/17 18:48:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

/*int main(void)
{
	char    testChar = 'A';

	if (ft_isalpha(testChar))
	{
		printf("%c is an alphabet letter.\n", testChar);
	}
	else
	{
		printf("%c is not an alphabet letter.\n", testChar);
	}

	return (0);
}*/