/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:26:14 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/15 10:47:19 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlench(char *str, char c)
{
	size_t len;

	len = 0;
	while (str[len] != c && str[len] != '\0')
		len++;
	return (len);
}

static size_t	ft_word_count(char *s, char c)
{
	size_t	i;
	size_t	word_count;
	int		flag;

	i = 0;
	flag = 1;
	word_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			flag = 1;
		else if (flag == 1)
		{
			word_count++;
			flag = 0;
		}
		i++;
	}
	return (word_count);
}

static void		*ft_remove(char **str, size_t cur_word)
{
	size_t	i;

	i = 0;
	while (i <= cur_word)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	return (NULL);
}

char			**ft_split(char *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(s) * (ft_word_count(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			str[j] = (char *)malloc(sizeof(s) * (ft_strlench(&s[i], c) + 1));
			if (!str[j])
				return (ft_remove(str, j));
			ft_strlcpy(str[j++], &s[i], (ft_strlench(&s[i], c) + 1));
			i = i + ft_strlench(&s[i], c);
		}
	}
	str[j] = NULL;
	return (str);
}
