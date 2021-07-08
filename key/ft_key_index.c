/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:20:09 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/23 22:30:49 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Что делает функция:		Находит индекс ключа в массиве **g_env.g_envp.
**
** Возращаемое значение:	Успех	- Индекс ключа.
**							Ошибка	- (-1).
**
** Особенности:				Нет.
**							Не передвигает строку форматирования.
*/

int		ft_key_index(char *my_key)
{
	int	flag;
	int	key_i;
	int	key_len;

	flag = 1;
	key_i = -1;
	key_len = ft_key_len(my_key);
	if (key_len <= 0)
		return (-1);
	while (g_env.g_env[++key_i] && flag != 0)
		flag = ft_strncmp(my_key, g_env.g_env[key_i], key_len);
	if (flag)
		return (-1);
	return (key_i - 1);
}
