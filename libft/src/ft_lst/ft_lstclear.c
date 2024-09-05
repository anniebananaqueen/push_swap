/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:13:35 by apatkano          #+#    #+#             */
/*   Updated: 2024/09/05 10:36:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*bla;

	if (lst && *lst)
	{
		while (*lst)
		{
			bla = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = bla;
		}
		*lst = 0;
	}
}
