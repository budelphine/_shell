/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_canon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:56:28 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/22 16:07:35 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_switch_canon_on(t_hist *tmp)
{
	struct termios	*term;

	term = &tmp->term;
	tcgetattr(0, term);
	term->c_lflag |= ECHO;
	term->c_lflag |= ICANON;
	tcsetattr(0, TCSANOW, term);
	tgetent(0, tmp->term_name);
}

void	ft_switch_canon_off(t_hist *tmp)
{
	struct termios	*term;

	term = &tmp->term;
	tcgetattr(0, term);
	term->c_lflag &= ~(ECHO);
	term->c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, term);
	tgetent(0, tmp->term_name);
}
