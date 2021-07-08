/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_slash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:49:01 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/15 15:55:16 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Что делает функция:		Парсит значения после \.
**
** Возращаемое значение:	Значение после экранирования.
**
** Особенности:				Передвигает строку **format.
**							- Обрабатывает экранирование в "";
**							- Обрабатывает обычное экранирование;
*/

char	*ft_parse_strong_slash(char **format)
{
	char	*str;

	str = ft_substr(*format, 1, 1);
	*format += 2;
	return (str);
}

char	*ft_parse_normal_slash(char **format)
{
	char	*str;

	if (ft_is_symbol(S_NSLH, *(*format + 1)))
		str = ft_substr(*format, 1, 1);
	else
		str = ft_substr(*format, 0, 2);
	*format += 2;
	return (str);
}

char	*ft_parse_slash(char **format, int flag)
{
	char	*str;

	if (flag)
		str = ft_parse_strong_slash(format);
	if (!flag)
		str = ft_parse_normal_slash(format);
	return (str);
}
