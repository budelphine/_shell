/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:39:17 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/15 11:20:01 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Что делает функция:		Создает **новый массив для команды
**							и ее параметров.
**
** Возращаемое значение:	Успех	- **Новый массив.
**							Ошибка	- NULL.
**
** Особенности:				Удаляет старый массив.
*/

char	**ft_add_param(char **old_arr, char *new_param, int len_arr)
{
	int		old_len_arr;
	char	**new_arr;

	old_len_arr = len_arr;
	new_arr = (char **)malloc(sizeof(char *) * (len_arr + 2));
	if (!new_arr || !new_param)
		ft_error(E_MLC, E_CODE, E_FD);
	new_arr[len_arr + 1] = NULL;
	new_arr[len_arr] = new_param;
	while (--len_arr >= 0)
		new_arr[len_arr] = old_arr[len_arr];
	ft_remove_pptr(old_arr);
	return (new_arr);
}
