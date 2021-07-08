/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:51:53 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/19 14:27:01 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Что делает функция:		Функция strnstr ищет первое вхождение строки,
**							на которую указывает аргумент str1, в строку,
**							на которую указывает аргумент str2. Длины (len).
**
** Возращаемое значение:	(char *) Указатель на первое вхождение
**							строки str1 в строке str2. Иначе NULL.
**
** Особенности:				Если строка str1 имеет нулевую длину,
**							то функция вернет указатель на начало строки str2.
*/

char	*ft_strnstr(char *str1, char *str2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*str2 == '\0')
		return ((char*)str1);
	while (str1[i])
	{
		j = 0;
		while ((str1[i + j] == str2[j])
				&& (i + j < len))
		{
			j++;
			if (str2[j] == '\0')
				return ((char*)str1 + i);
		}
		i++;
	}
	if (str1[i] == str2[0] && i < len)
		return ((char*)str1 + i);
	return (NULL);
}
