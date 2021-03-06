/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:22:51 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/21 20:19:38 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Что делает функция:		Печатает строку и дополняет ее
**							символом '\n' в конце.
**
** Возращаемое значение:	Нет.
**
** Особенности:				Нет.
*/

void	ft_putendl_fd(char *str, int fd)
{
	if (fd < 0)
		return ;
	if (!str)
		return ;
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}
