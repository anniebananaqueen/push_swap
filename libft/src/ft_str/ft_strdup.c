/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:55:17 by apatkano          #+#    #+#             */
/*   Updated: 2024/08/17 18:50:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, (ft_strlen(s) + 1));
	return (str);
}
