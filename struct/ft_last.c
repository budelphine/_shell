/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:42:58 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/12 12:42:40 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_flag	*ft_lst_prev(t_flag *head, t_flag *cur_flag)
{
	t_flag	*prev_flag;
	t_flag	*prev_pipe;

	if (!head || !cur_flag)
		return (NULL);
	prev_flag = head;
	prev_pipe = prev_flag->next_pipe;
	while (prev_flag)
	{
		while (prev_pipe)
		{
			if (prev_pipe->next == cur_flag)
				return (prev_pipe);
			prev_pipe = prev_pipe->next;
		}
		if (prev_flag->next == cur_flag)
			return (prev_flag);
		prev_flag = prev_flag->next;
	}
	return (NULL);
}

t_flag	*ft_lst_last(t_flag *cur_flag)
{
	t_flag	*last_lst;

	last_lst = cur_flag;
	if (!last_lst)
		return (NULL);
	while (last_lst->next)
		last_lst = last_lst->next;
	while (last_lst->next_pipe)
		last_lst = last_lst->next_pipe;
	return (last_lst);
}

t_flag	*ft_flag_last(t_flag *cur_flag)
{
	t_flag	*last_flag;

	last_flag = cur_flag;
	if (!last_flag)
		return (NULL);
	while (last_flag->next)
		last_flag = last_flag->next;
	return (last_flag);
}
