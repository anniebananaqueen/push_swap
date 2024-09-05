/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:18:42 by apatkano          #+#    #+#             */
/*   Updated: 2024/09/05 10:32:11 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*str;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	i = start;
	l = 0;
	while (l < len && s[i] != '\0')
	{
		i++;
		l++;
	}
	str = malloc(l + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s + start, l + 1);
	return (str);
}
