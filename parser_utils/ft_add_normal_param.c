/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_normal_param.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:39:15 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/15 16:20:18 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Что делает функция:		Парсит обычные параметры
**							без кавычек.
**
** Возращаемое значение:	Обработанный параметр.
**
** Особенности:				Двигает **format;
*/

char	*ft_add_normal_param(char **format)
{
	char	*new_str;
	char	*tmp_param;
	char	*new_param;

	new_param = ft_strdup("");
	while (**format && !ft_is_symbol(S_NNRM, **format))
	{
		if (**format == '$')
			new_str = ft_parse_define(format);
		else if (**format == '\\')
			new_str = ft_parse_slash(format, 1);
		else
			new_str = ft_parse_normal(format, S_ALL);
		tmp_param = new_param;
		new_param = ft_strjoin(new_param, new_str);
		ft_strdel(&tmp_param);
		ft_strdel(&new_str);
	}
	return (new_param);
}
