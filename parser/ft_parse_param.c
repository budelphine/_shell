/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:05:50 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/17 12:15:50 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Что делает функция:		Парсит параметр в зависимости
**							от условия.
**
** Возращаемое значение:	Нет.
**
** Особенности:				Двигает **format;
*/

void	ft_parse_param(char **format, t_flag *flag)
{
	char	*new_str;
	char	*tmp_param;
	char	*new_param;

	ft_move_format(S_SPC, format);
	if (ft_is_symbol(S_CMD, **format) || !(**format))
		return ;
	new_param = ft_strdup("");
	while (!ft_is_symbol(S_SCMD, **format) && **format)
	{
		if (ft_is_symbol(S_OQTE, **format))
			new_str = ft_add_quote(format);
		else if (ft_is_symbol(S_DQTE, **format))
			new_str = ft_add_double_quote(format);
		else
			new_str = ft_add_normal_param(format);
		tmp_param = new_param;
		new_param = ft_strjoin(new_param, new_str);
		ft_strdel(&tmp_param);
		ft_strdel(&new_str);
	}
	new_param = ft_add_str_space(format, new_param, flag);
	flag->param = ft_add_param(flag->param, new_param, flag->count_param);
}
