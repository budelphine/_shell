/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:52:08 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/19 15:21:09 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_move_format(char *set, char **format)
{
	int	res;

	res = 0;
	while (ft_is_symbol(set, (*format)[res]))
		res++;
	*format += res;
	return (res);
}

void	ft_move_oqte(char **format)
{
	ft_move_format(S_SPC, format);
	if (!ft_is_symbol(S_OQTE, **format))
		return ;
	(*format)++;
	while (**format && !ft_is_symbol(S_OQTE, **format))
		(*format)++;
	if (ft_is_symbol(S_OQTE, **format))
		(*format)++;
}

void	ft_move_dqte(char **format)
{
	ft_move_format(S_SPC, format);
	if (!ft_is_symbol(S_DQTE, **format))
		return ;
	(*format)++;
	while (**format && !ft_is_symbol(S_DQTE, **format))
	{
		if (**format == '\\')
			(*format)++;
		(*format)++;
	}
	if (ft_is_symbol(S_DQTE, **format))
		(*format)++;
}

void	ft_move_normal(char **format)
{
	ft_move_format(S_SPC, format);
	if (ft_is_symbol(S_NNRM, **format))
		return ;
	while (**format && !ft_is_symbol(S_NNRM, **format))
	{
		if (**format == '\\')
			(*format)++;
		(*format)++;
	}
}

void	ft_move_cmd(char **format)
{
	if (**format && !ft_strncmp(S_RRED, *format, 2))
		*format += 2;
	else if (**format == '>')
		(*format)++;
	else if (**format == '<')
		(*format)++;
	else if (**format == '|')
		(*format)++;
	else if (**format == ';')
		(*format)++;
}
