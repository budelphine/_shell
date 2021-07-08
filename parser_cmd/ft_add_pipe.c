/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:21:41 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/17 12:23:58 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_flag	*ft_add_pipe(t_flag *flag)
{
	t_flag	*new_flag;

	new_flag = ft_flag_new();
	flag->next_pipe = new_flag;
	return (new_flag);
}
