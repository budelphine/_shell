/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:56:08 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/17 15:13:28 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
** Что делает функция:		Считывает названия файлов для редиректа.
**
** Возращаемое значение:	void.
**
** Особенности:				Добавляет по одному редиректу за раз.
** 							Двигается по **format.
*/

static void	ft_check_redirect(char **format, t_flag *flag)
{
	int	*new_red_i;
	int	i;

	i = -1;
	new_red_i = (int *)malloc(sizeof(int) * (flag->all_red + 1));
	if (!new_red_i)
		ft_error(E_MLC, E_CODE, E_FD);
	while (++i < flag->all_red - 1)
		new_red_i[i] = flag->red_i[i];
	if (flag->rew_red == flag->all_red)
	{
		new_red_i[i] = 2;
		*format += 1;
	}
	else if (flag->dir_red == flag->all_red)
		new_red_i[i] = 1;
	else if (flag->rev_red == flag->all_red)
		new_red_i[i] = 0;
	*format += 1;
	ft_move_format(S_SPC, format);
	free(flag->red_i);
	flag->red_i = new_red_i;
}

t_flag		*ft_add_redirect(char **format, t_flag *flag)
{
	char	*new_str;
	char	*new_file;
	char	*tmp_file;

	ft_check_redirect(format, flag);
	new_file = ft_strdup("");
	while (!ft_is_symbol(S_SCMD, **format) && **format)
	{
		if (!ft_is_symbol(S_QTE, **format))
			new_str = ft_add_normal_param(format);
		else if (**format == '\'')
			new_str = ft_add_quote(format);
		else if (**format == '\"')
			new_str = ft_add_double_quote(format);
		tmp_file = new_file;
		new_file = ft_strjoin(new_file, new_str);
		ft_strdel(&tmp_file);
		ft_strdel(&new_str);
	}
	flag->file = ft_add_param(flag->file, new_file, flag->all_red - 1);
	return (flag);
}
