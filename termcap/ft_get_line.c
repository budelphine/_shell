/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:56:20 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/23 18:54:42 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_init_hist(t_hist *tmp)
{
	tmp->cur_hist = 0;
	tmp->cur_hist = tmp->max_hist;
	if (tmp->max_hist > 0)
		return ;
	tmp->max_hist = 0;
	tmp->hist = (char **)malloc(sizeof(char *) * 2);
	tmp->hist[0] = ft_strdup("");
	tmp->hist[1] = NULL;
}

void	ft_add_hist(t_hist *tmp, char **format)
{
	if ((tmp->del_tmp = ft_strchr(tmp->hist[tmp->cur_hist], '\n')))
		*tmp->del_tmp = '\0';
	tmp->max_hist++;
	tmp->del_tmp = tmp->hist[tmp->max_hist - 1];
	tmp->hist[tmp->max_hist - 1] = ft_strdup(tmp->hist[tmp->cur_hist]);
	ft_strdel(&tmp->del_tmp);
	tmp->hist = ft_add_param(tmp->hist, ft_strdup(""), tmp->max_hist);
	*format = tmp->hist[tmp->cur_hist];
}

void	ft_switch_key(t_hist *tmp)
{
	if (!ft_strncmp(tmp->buf, "\4", 1) && \
		ft_strlen(tmp->hist[tmp->cur_hist]) != 0)
		tmp->buf[0] = '\0';
	if (!ft_strncmp(tmp->buf, "\e[A", 4))
		ft_hist_prev(tmp->hist, &tmp->cur_hist, &tmp->max_hist);
	else if (!ft_strncmp(tmp->buf, "\e[B", 4))
		ft_hist_next(tmp->hist, &tmp->cur_hist, &tmp->max_hist);
	else if (!ft_strncmp(tmp->buf, "\177", 1))
		ft_backspace(tmp->hist, &tmp->cur_hist);
	else if (!ft_strncmp(tmp->buf, "\e[C", 4) || \
			!ft_strncmp(tmp->buf, "\e[D", 4))
		return ;
	else
		ft_print(tmp->hist, tmp->buf, tmp->byte_readed, &tmp->cur_hist);
}

int		ft_get_line(char **format)
{
	static t_hist	tmp;

	ft_init_hist(&tmp);
	ft_switch_canon_off(&tmp);
	tputs(save_cursor, 1, ft_putchar);
	while (ft_strncmp(tmp.buf, "\4", 1))
	{
		tmp.byte_readed = read(0, tmp.buf, 100);
		tmp.buf[tmp.byte_readed] = '\0';
		ft_switch_key(&tmp);
		if (!ft_strncmp(tmp.buf, "\n", 1))
			break ;
	}
	ft_switch_canon_on(&tmp);
	if (!ft_strncmp(tmp.buf, "\4", 1))
		return (0);
	ft_add_hist(&tmp, format);
	return (1);
}
