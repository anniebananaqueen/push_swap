/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:00:01 by apatkano          #+#    #+#             */
/*   Updated: 2024/09/05 10:36:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	size_t	i;
	void	*ptr;

	if (nmeb == 0 || size == 0)
	{
		nmeb = 1;
		size = 1;
	}
	i = nmeb * size;
	if (i / nmeb != size)
		return (NULL);
	ptr = malloc(i);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, i);
	return (ptr);
}
