/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:10:32 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/22 17:49:07 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char	*map_str;
	int		i;

	if (!s || !f)
		return (NULL);
	map_str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!map_str)
		return (NULL);
	i = -1;
	while (s[++i])
		map_str[i] = f(i, s[i]);
	map_str[i] = '\0';
	return (map_str);
}
