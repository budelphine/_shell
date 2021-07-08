/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:30:40 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/22 17:46:25 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t count)
{
	size_t				i;
	unsigned char		*dest2;
	const unsigned char	*src2;

	dest2 = (unsigned char*)dest;
	src2 = (unsigned char*)src;
	i = 0;
	if (!src && !dest)
		return (NULL);
	if (src2 < dest2)
	{
		while (++i <= count)
			dest2[count - i] = src2[count - i];
	}
	else
	{
		while (count-- > 0)
			*(dest2++) = *(src2++);
	}
	return (dest);
}
