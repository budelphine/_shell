/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:01:35 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/17 16:09:07 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Что делает функция:		Формирует список команд и параметров.
**
** Возращаемое значение:	Список команд и параметров.
**
** Особенности:				Обрабатывает ошибки:
**							- syntax error near unexpected token `;'
*/

t_flag		*ft_parser(char **format)
{
	t_flag	*flag;
	t_flag	*head;

	head = ft_flag_new();
	flag = head;
	while (!flag->semi && !flag->end)
	{
		ft_parse_param(format, flag);
		ft_parse_info(format, flag);
		flag = ft_parse_cmd(format, flag);
	}
	if (!flag->name)
		ft_lst_clear(&head, &ft_remove_arr);
	return (head);
}
