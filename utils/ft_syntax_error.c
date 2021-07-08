/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:49:46 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/23 20:10:54 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_check_cmd(char **format)
{
	char	*token;
	int		oth_cmd;
	int		semi;

	semi = 0;
	oth_cmd = 0;
	token = NULL;
	ft_move_format(S_SPC, format);
	if (!ft_is_symbol(S_CMD, **format))
		return (0);
	oth_cmd += (ft_is_symbol(S_CMD, **format) && (**format != ';') ? 1 : 0);
	semi += (**format == ';' ? 10 : 0);
	ft_move_cmd(format);
	ft_move_format(S_SPC, format);
	oth_cmd += (ft_is_symbol(S_CMD, **format) && (**format != ';') ? 1 : 0);
	semi += (**format == ';' ? 1 : 0);
	if ((semi == 11) || (oth_cmd && semi) || (oth_cmd == 2) \
		|| (oth_cmd && ft_check_new_line(*format)))
	{
		token = ft_choose_token(*format);
		ft_print_syntax_error(&token);
		return (1);
	}
	return (0);
}

static int	ft_is_cmd_error(char *format)
{
	int		res;

	res = 0;
	while (*format != '\0' && !res)
	{
		ft_move_normal(&format);
		ft_move_oqte(&format);
		ft_move_dqte(&format);
		res = ft_check_cmd(&format);
	}
	return (res);
}

static int	ft_is_only_cmd(char *format)
{
	char	*token;

	token = NULL;
	ft_move_format(S_SPC, &format);
	if (!ft_is_symbol(S_CMD, *format))
		return (0);
	token = ft_choose_token(format);
	ft_print_syntax_error(&token);
	return (1);
}

static int	ft_is_empthy_line(char *format)
{
	ft_move_format(S_SPC, &format);
	if (*format == '\0')
		return (1);
	return (0);
}

int			ft_syntax_error(char *format)
{
	int	res;

	res = 0;
	res += ft_is_empthy_line(format);
	res += ft_is_only_cmd(format);
	if (!res)
		res += ft_is_cmd_error(format);
	return (res);
}
