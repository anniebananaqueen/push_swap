/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:55:15 by apatkano          #+#    #+#             */
/*   Updated: 2024/08/17 18:51:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;
	int		i;

	if (s1 == NULL || set == NULL)
		return (0);
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = (ft_strlen(s1) - 1);
	while (end > 0 && is_in_set(s1[end], set))
		end--;
	if (end + 1 <= start)
		return (ft_strdup(""));
	str = malloc(end - start + 2);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
