/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 11:47:50 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/11 16:48:39 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_list;
	t_list	*current_list;

	if (!lst)
		return ;
	current_list = *lst;
	while (current_list)
	{
		next_list = current_list->next;
		if (del != NULL)
			del(current_list->content);
		free(current_list);
		current_list = NULL;
		current_list = next_list;
	}
	*lst = NULL;
}
