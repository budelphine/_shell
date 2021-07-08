/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 19:43:14 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/15 11:20:23 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_flag	*ft_flag_new(void)
{
	t_flag	*tmp;

	tmp = malloc(sizeof(t_flag));
	if (!tmp)
		ft_error(E_MLC, E_CODE, E_FD);
	*tmp = ft_init_flag();
	return (tmp);
}
