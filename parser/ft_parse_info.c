/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:02:51 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/17 15:07:26 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Что делает функция:		Добавляет информацию о текущем
**							элементе списка команд.
**
** Возращаемое значение:	Нет.
**
** Особенности:				Нет.
*/

void	ft_parse_info(char **format, t_flag *flag)
{
	ft_move_format(S_SPC, format);
	if (**format == '\0')
		flag->end++;
	if (flag->param[flag->count_param])
		flag->count_param++;
	if (ft_is_symbol(S_RED, **format))
		flag->all_red++;
	if (**format && !ft_strncmp(S_RRED, *format, 2))
		flag->rew_red = flag->all_red;
	else if (**format == '>')
		flag->dir_red = flag->all_red;
	else if (**format == '<')
		flag->rev_red = flag->all_red;
	else if (**format == '|')
		flag->pipe++;
	else if (**format == ';')
		flag->semi++;
}
