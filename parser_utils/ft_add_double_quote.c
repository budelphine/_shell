/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_double_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:15:41 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/15 16:20:02 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Что делает функция:		Добавляет всю "строку" между кавычками.
**
** Возращаемое значение:	Новый параметр.
**
** Особенности:				Передвигает строку **format.
**							- Заменяет значения после $;
**							- Заменяет значения после \;
**							- Парсит обычные значения;
*/

char	*ft_add_double_quote(char **format)
{
	char	*new_str;
	char	*tmp_param;
	char	*new_param;

	(*format)++;
	new_param = ft_strdup("");
	while (!ft_is_symbol(S_DQTE, **format) && **format)
	{
		if (ft_is_symbol(S_DEF, **format))
			new_str = ft_parse_define(format);
		else if (ft_is_symbol(S_SLASH, **format))
			new_str = ft_parse_slash(format, 0);
		else
			new_str = ft_parse_normal(format, S_PSM);
		tmp_param = new_param;
		new_param = ft_strjoin(new_param, new_str);
		ft_strdel(&tmp_param);
		ft_strdel(&new_str);
	}
	(*format)++;
	return (new_param);
}
