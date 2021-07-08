/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:40:49 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/15 16:20:32 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Что делает функция:		Добавляет всю 'строку' между кавычками.
**
** Возращаемое значение:	Новый параметр.
**
** Особенности:				Передвигает строку **format.
*/

char	*ft_add_quote(char **format)
{
	char	*new_param;

	(*format)++;
	new_param = *format;
	while (!ft_is_symbol(S_OQTE, **format) && **format)
		(*format)++;
	new_param = ft_substr(new_param, 0, *format - new_param);
	if (ft_is_symbol(S_OQTE, **format))
		(*format)++;
	return (new_param);
}
