/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:07:26 by budelphi          #+#    #+#             */
/*   Updated: 2021/01/22 17:48:33 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_set(char s, char *set)
{
	int		flag;
	size_t	i;

	i = -1;
	flag = 0;
	while (set[++i] && !flag)
	{
		if (s == set[i])
			flag = 1;
	}
	return (flag);
}

char		*ft_strtrim(char *str, char *set)
{
	size_t	end_i;
	size_t	start_i;

	end_i = 0;
	start_i = 0;
	if (!str)
		return (NULL);
	end_i = ft_strlen(str);
	if (end_i != 0)
		end_i--;
	while (ft_find_set(str[start_i], set) == 1 && start_i <= end_i)
		start_i++;
	while (ft_find_set(str[end_i], set) == 1 && end_i > start_i)
		end_i--;
	return (ft_substr(str, start_i, end_i - start_i + 1));
}
