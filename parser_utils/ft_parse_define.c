/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_define.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:48:23 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/23 22:27:32 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_parse_gstatus(char **format)
{
	char	*new_str;

	(*format)++;
	new_str = ft_itoa(g_env.g_status);
	return (new_str);
}

char	*ft_parse_normal_key(char **format)
{
	int		key_i;
	int		key_len;
	char	*new_str;

	key_i = -1;
	key_len = 0;
	key_i = ft_key_index(*format);
	key_len = ft_key_len(*format);
	*format += key_len;
	new_str = ft_get_key_value(key_i);
	if (!new_str)
		new_str = ft_strdup("");
	return (new_str);
}

char	*ft_parse_define(char **format)
{
	int		key_len;
	char	*new_str;

	(*format)++;
	new_str = NULL;
	key_len = ft_key_len(*format);
	if (**format == '?')
		new_str = ft_parse_gstatus(format);
	else if (key_len > 0)
		new_str = ft_parse_normal_key(format);
	else if ((ft_is_symbol(S_ENDCQ, **format) || **format == '\0')
			&& key_len != -1)
	{
		new_str = ft_strdup("$");
		(*format)++;
	}
	if (!new_str && key_len == -1)
		(*format)++;
	if (!new_str)
		new_str = ft_strdup("");
	return (new_str);
}
