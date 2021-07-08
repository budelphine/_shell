/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:06:55 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/22 17:50:26 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*newstr;

	i = -1;
	j = -1;
	len = 0;
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	len = ft_strlen(str1) + ft_strlen(str2);
	newstr = (char *)malloc(sizeof(*newstr) * (len + 1));
	if (!newstr)
		return (NULL);
	while (str1[++i])
		newstr[i] = str1[i];
	while (str2[++j])
		newstr[i + j] = str2[j];
	newstr[i + j] = '\0';
	return (newstr);
}
