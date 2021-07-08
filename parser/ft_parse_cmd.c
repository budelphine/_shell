/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:00:16 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/17 15:45:03 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_flag	*ft_parse_cmd(char **format, t_flag *flag)
{
	t_flag	*new_flag;

	new_flag = flag;
	flag->name = flag->param[0];
	ft_move_format(S_SPC, format);
	if (ft_is_symbol(S_RED, **format))
		new_flag = ft_add_redirect(format, flag);
	if (ft_is_symbol(S_PIPE, **format))
		new_flag = ft_add_pipe(flag);
	if (ft_is_symbol(S_SPIP, **format))
		(*format)++;
	return (new_flag);
}
