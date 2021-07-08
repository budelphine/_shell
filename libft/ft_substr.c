/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:06:28 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/22 17:47:11 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	if (!str || len <= 0 || start >= ft_strlen(str))
		return (ft_strdup(""));
	i = -1;
	s_len = ft_strlen(str);
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (++i < len)
		substr[i] = str[start + i];
	substr[i] = '\0';
	return (substr);
}
