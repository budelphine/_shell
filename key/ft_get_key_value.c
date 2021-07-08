/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_key_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:20:33 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/23 22:30:40 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Что делает функция:		Возвращает копию значения ключа по индексу.
**
** Возращаемое значение:	Успех	- Значение ключа.
**							Ошибка	- NULL.
**
** Особенности:				Возвращает копию значения.
**							Не передвигает строку форматирования.
*/

char	*ft_get_key_value(int key_index)
{
	char	*key_value;
	int		key_len;

	if (key_index < 0)
		return (NULL);
	key_len = ft_key_len(g_env.g_env[key_index]);
	key_value = ft_strdup(g_env.g_env[key_index] + key_len + 1);
	return (key_value);
}
