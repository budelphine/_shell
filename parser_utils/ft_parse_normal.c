/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 14:00:32 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/11 12:35:59 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_parse_normal(char **format, char *set)
{
	char	*new_str;

	new_str = *format;
	while (!ft_is_symbol(set, **format) && **format)
		(*format)++;
	new_str = ft_substr(new_str, 0, *format - new_str);
	return (new_str);
}
