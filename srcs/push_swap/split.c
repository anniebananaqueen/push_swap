/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apatkano <apatkano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:13:09 by codespace         #+#    #+#             */
/*   Updated: 2024/10/14 17:39:42 by apatkano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_split(char **result)
{
	size_t	i;

	i = 0;
	if (!result)
		return ;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	*substring(const char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || start >= ft_strlen(s) || len == 0)
		return (NULL);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static int	substring_count(char *s, char delimiter)
{
	int		count;
	bool	in_substring;

	count = 0;
	while (*s != '\0')
	{
		in_substring = false;
		while (*s == delimiter && *s)
			s++;
		while (*s != delimiter && *s)
		{
			if (!in_substring)
			{
				count++;
				in_substring = true;
			}
			s++;
		}
	}
	return (count);
}

static int	add_substring(char **result, char *s, size_t start, size_t end)
{
	char	*substr;

	substr = substring(s, start, end - start);
	if (!substr)
	{
		free_split(result);
		return (-1);
	}
	result[end] = substr;
	return (0);
}

char	**split_string(char *s, char delimiter)
{
	int		i;
	int		j;
	int		start;
	char	**result;

	if (!s)
		return (NULL);
	result = malloc((substring_count(s, delimiter) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == delimiter)
			i++;
		start = i;
		while (s[i] && s[i] != delimiter)
			i++;
		if (i > start && add_substring(result, s, start, i) == -1)
			return (NULL);
		j++;
	}
	result[j] = NULL;
	return (result);
}
