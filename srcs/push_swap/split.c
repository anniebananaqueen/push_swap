/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:13:09 by codespace         #+#    #+#             */
/*   Updated: 2024/09/02 10:46:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_split (char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	*substring(const char *s, int start, int len)
{
	char	*sub;
	int		i;

	if (!s || start < 0 || len < 0 || start >= (int)ft_strlen(s))
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

int	substring_count(const char *s, char delimeter)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s != delimeter && in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		else if (*s == delimeter)
			in_substring =0;
		s++;
	}
	return (count);
}

char	**split_string(const char *s, char delimiter)
{
	int	i;
	int	j;
	int	start;
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
		if (i > start)
		{
			result[j] = substring(s, start, i - start);
			if (!result[j++])
				return (free_split(result), NULL);
		}
	}
	result[j] = NULL;
	return (result);
}
