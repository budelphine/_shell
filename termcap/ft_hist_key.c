/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hist_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:59:18 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/23 17:55:41 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_putchar(int ch)
{
	write(1, &ch, 1);
	return (1);
}

void	ft_backspace(char **hist, int *cur_hist)
{
	int	len;

	len = ft_strlen(hist[*cur_hist]);
	if (len <= 0)
		return ;
	tputs(cursor_left, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	hist[*cur_hist][len - 1] = '\0';
}

void	ft_print(char **hist, char buf[], int byte_readed, int *cur_hist)
{
	char	*del_str;

	del_str = hist[*cur_hist];
	write(1, buf, byte_readed);
	hist[*cur_hist] = ft_strjoin(hist[*cur_hist], buf);
	ft_strdel(&del_str);
}

void	ft_hist_prev(char **hist, int *cur_hist, int *max_hist)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	if (*cur_hist > 0)
		ft_putstr_fd(hist[--(*cur_hist)], 1);
	else
		ft_putstr_fd(hist[*cur_hist], 1);
}

void	ft_hist_next(char **hist, int *cur_hist, int *max_hist)
{
	tputs(restore_cursor, 1, ft_putchar);
	tputs(tigetstr("ed"), 1, ft_putchar);
	if (*cur_hist < *max_hist)
		ft_putstr_fd(hist[++(*cur_hist)], 1);
	else
		ft_putstr_fd(hist[*cur_hist], 1);
}
