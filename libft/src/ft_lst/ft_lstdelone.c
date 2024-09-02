/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:40:51 by apatkano          #+#    #+#             */
/*   Updated: 2024/08/17 18:49:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst)
	{
		(del)(lst->content);
		free(lst);
	}
}
