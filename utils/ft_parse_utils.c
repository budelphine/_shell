/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 19:53:22 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/17 14:52:23 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		ft_is_symbol(char *set, char ch)
{
	int	flag;

	flag = 0;
	while (*set && !flag)
	{
		if (ch == *set)
			flag = 1;
		set++;
	}
	return (flag);
}

char	*ft_add_str_space(char **format, char *new_param, t_flag *flag)
{
	char	*tmp_param;
	int		count_param;
	int		res;

	count_param = flag->count_param;
	if (count_param < 1 || ft_strncmp(flag->param[0], C_ECHO, 5)
		|| !ft_strncmp(new_param, "", 1))
		return (new_param);
	tmp_param = new_param;
	res = ft_move_format(S_SPC, format);
	if (count_param >= 1 && !ft_is_symbol(S_CMD, **format) && res && **format)
	{
		new_param = ft_strjoin(new_param, S_SPC);
		ft_strdel(&tmp_param);
	}
	if (!new_param)
		ft_error(E_MLC, E_CODE, E_FD);
	return (new_param);
}

void	ft_remove_arr(char **arr, int i_cur)
{
	int	i;

	i = -1;
	while (++i < i_cur)
	{
		free(arr[i]);
		arr[i] = NULL;
	}
	if (arr)
		free(arr);
	arr = NULL;
}

void	*ft_remove_pptr(char **arr)
{
	free(arr);
	arr = NULL;
	return (NULL);
}
