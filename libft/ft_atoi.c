/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:10:54 by budelphi          #+#    #+#             */
/*   Updated: 2021/02/11 14:48:00 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Что делает функция:		Пропускает символы " \t\v\r\f\n"
**							и переводит строку цифр в число.
**
** Возращаемое значение:	Полученное число.
**
** Особенности:				Переполнение long long обрабатывает как 0 или -1
*/

static int	ft_is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

int			ft_atoi(char *str)
{
	unsigned long int	result;
	int					sign;

	sign = 1;
	result = 0;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while ((*str != '\0') && ft_is_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		if (result >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (result > 9223372036854775807 && sign == -1)
			return (0);
		str++;
	}
	return ((int)(result * sign));
}
