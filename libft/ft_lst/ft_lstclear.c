/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyu <dyu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 15:49:04 by dyu               #+#    #+#             */
/*   Updated: 2021/01/05 13:58:57 by dyu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*prev;

	if (*lst == NULL || !(current = *lst) || !del)
		return ;
	while (current->next != NULL)
	{
		prev = current;
		del(current->content);
		ft_memdel(current);
		current = prev->next;
	}
	del(current->content);
	ft_memdel(current);
	*lst = NULL;
}
