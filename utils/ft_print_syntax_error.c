/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_syntax_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:56:33 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/23 22:27:15 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_check_new_line(char *line)
{
	ft_move_cmd(&line);
	ft_move_format(S_SPC, &line);
	if (*line == '\0')
		return (1);
	return (0);
}

int		ft_print_syntax_error(char **token)
{
	if (!*token)
		return (0);
	if (**token == '\0')
		ft_putendl_fd(E_RSEN, 2);
	else
	{
		ft_putstr_fd(E_RSET, 2);
		ft_putendl_fd(*token, 2);
	}
	ft_strdel(token);
	g_env.g_status = 258;
	return (1);
}

char	*ft_choose_token(char *format)
{
	if (!ft_strncmp(format, ">>", 2))
		return (ft_strdup(">>\'"));
	else if (!ft_strncmp(format, "<<", 2))
		return (ft_strdup("<<\'"));
	else if (!ft_strncmp(format, ">|", 2))
		return (ft_strdup(">|\'"));
	else if (!ft_strncmp(format, ";;", 2))
		return (ft_strdup(";;\'"));
	else if (!ft_strncmp(format, "||", 2))
		return (ft_strdup("||\'"));
	else if (!ft_strncmp(format, "<", 1))
		return (ft_strdup("<\'"));
	else if (!ft_strncmp(format, ">", 1))
		return (ft_strdup(">\'"));
	else if (!ft_strncmp(format, ";", 1))
		return (ft_strdup(";\'"));
	else if (!ft_strncmp(format, "|", 1))
		return (ft_strdup("|\'"));
	else if (!ft_strncmp(format, "", 1))
		return (ft_strdup(""));
	return (NULL);
}
