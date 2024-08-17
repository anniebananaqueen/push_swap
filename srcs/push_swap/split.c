/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:13:09 by codespace         #+#    #+#             */
/*   Updated: 2024/08/15 12:55:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	word_counter(char const *s, char c)
{
	int	i;
	int	state;
	int	word_count;

	i = 0;
	state = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (state == 0 && s[i] != c)
		{
			word_count++;
			state = 1;
		}
		if (state == 1 && s[i] == c)
		{
			state = 0;
		}
		i++;
	}
	return (word_count);
}

static int	strlen_wannabe(char const *s, char c, int start)
{
	int	i;

	i = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		start++;
		i++;
	}
	return (i);
}

static int	strlcpy_wannabe(char *array, const char *s, int start, char c)
{
	int	i;

	i = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		array[i] = s[start];
		start++;
		i++;
	}
	array[i] = '\0';
	return (ft_strlen(array));
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;
	int		state;

	array = malloc(sizeof(char *) * (word_counter(s, c) + 1));
	i = 0;
	j = 0;
	state = 0;
	while (s[i])
	{
		if (state == 0 && s[i] != c)
		{
			array[j] = malloc(sizeof(char) * (strlen_wannabe(s, c, i) + 1));
			i = i + strlcpy_wannabe((array[j]), s, i, c);
			state = 1;
			j++;
		}
		if (state == 1 && s[i] == c)
			state = 0;
		if (s[i] != '\0')
			i++;
	}
	array[j] = NULL;
	return (array);
}