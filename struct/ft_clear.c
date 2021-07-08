/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 16:36:54 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/17 16:22:34 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lst_clear(t_flag **lst, void (*del)(char **, int))
{
	t_flag	*next_flag;
	t_flag	*cur_flag;

	if (!lst)
		return ;
	cur_flag = *lst;
	while (cur_flag)
	{
		next_flag = cur_flag->next_pipe;
		if (del)
			ft_lst_delone(&cur_flag, del);
		cur_flag = NULL;
		cur_flag = next_flag;
	}
	*lst = NULL;
}

void	ft_lst_delone(t_flag **flag, void (*del)(char **, int))
{
	t_flag	*cur_flag;

	cur_flag = *flag;
	if (!cur_flag)
		return ;
	if (del)
	{
		del(cur_flag->param, cur_flag->count_param);
		del(cur_flag->file, cur_flag->all_red);
		free(cur_flag->red_i);
	}
	free(cur_flag);
	*flag = NULL;
}
