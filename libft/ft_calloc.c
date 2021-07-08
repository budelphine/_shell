/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:47:22 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/20 22:38:53 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Что делает функция:		Выделяет блок памяти размером number * size байт,
**							причём весь блок заполнен нулями.
**
** Возращаемое значение:	 (void *) Указатель на область памяти.
**
** Особенности:				Нет.
*/

void	*ft_calloc(size_t count, size_t size)
{
	char	*addr;
	size_t	nbytes;
	size_t	i;

	i = 0;
	nbytes = count * size;
	addr = malloc(nbytes);
	if (!addr)
		return (NULL);
	while (nbytes--)
		addr[i++] = 0;
	return ((void *)addr);
}
