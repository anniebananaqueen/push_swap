/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:36:33 by marvin            #+#    #+#             */
/*   Updated: 2024/09/05 12:17:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t i;
    unsigned char *ptr = (unsigned char *)s;

    for (i = 0; i < n; i++)
    {
        if (ptr[i] == (unsigned char)c)
        {
            return (void *)(ptr + i);
        }
    }
    return NULL;
}
