/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:48:51 by apatkano          #+#    #+#             */
/*   Updated: 2024/09/05 10:37:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) || ft_isdigit(c)))
		return (1);
	return (0);
}

/*int main(void)
{
	char    testChar = 'A1';

	if (ft_isalnum(testChar))
	{
		printf("%c is alphanumeric.\n", testChar);
	}
	else
	{
		printf("%c is not alphanumeric.\n", testChar);
	}

	return (0);
}*/