/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:12:01 by apatkano          #+#    #+#             */
/*   Updated: 2024/08/17 18:50:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

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

// int	main(void)
// {
// 	char **babygirl;
// 	int		i = 0;

// 	babygirl = ft_split("aaa", '!');
// 	while (babygirl[i])
// 	{
// 		printf("%s\n", babygirl[i]);
// 		i++;
// 	}
// }

// state = 1
// word_count = 2;
// !!!aa!bb!!!cc = "aa","bb","cc",NULL
