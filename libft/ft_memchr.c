/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:35:31 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/22 17:46:03 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *src, int ch, size_t count)
{
	unsigned char	*src2;

	src2 = (unsigned char *)src;
	while (count--)
	{
		if (*src2 == ((unsigned char)ch))
			return (src2);
		else
			src2++;
	}
	return (NULL);
}
