/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: budelphi <budelphi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 16:45:26 by budelphi          #+#    #+#             */
/*   Updated: 2021/03/21 20:45:45 by budelphi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_save_fd(void)
{
	dup2(0, 3);
	dup2(1, 4);
}

int			main(int ac, char **av, char **env)
{
	if (ac != 1 || !av[0])
		ft_error(E_ARGC, N_CODE, N_FD);
	ft_save_fd();
	ft_create_genv(env);
	ft_minishell();
	return (0);
}
