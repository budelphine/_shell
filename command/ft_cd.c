/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjoella <rjoella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:49:24 by rjoella           #+#    #+#             */
/*   Updated: 2021/03/23 22:29:08 by rjoella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_chenge_pwd(char *pwd)
{
	char *old_pwd;
	char *work_dir;

	work_dir = getcwd(NULL, 0);
	old_pwd = ft_strjoin(pwd, work_dir);
	if (!old_pwd)
		ft_error(E_MLC, E_CODE, 2);
	if (!ft_check_arg(pwd))
		ft_put_arg(old_pwd);
	else
		ft_change_arg(old_pwd);
	free(old_pwd);
	free(work_dir);
}

void	ft_none_path(void)
{
	char *path;

	if (ft_check_key("HOME="))
	{
		path = ft_get_key_value(ft_key_index("HOME="));
		ft_chenge_pwd("OLDPWD=");
		ft_err_cd(chdir(path));
		ft_chenge_pwd("PWD=");
		free(path);
	}
	else
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		g_env.g_status = 1;
	}
}

void	ft_arg_minus(void)
{
	char *path;

	if (ft_check_arg("OLDPWD="))
	{
		path = ft_get_key_value(ft_key_index("OLDPWD="));
		ft_chenge_pwd("OLDPWD=");
		ft_err_cd(chdir(path));
		ft_chenge_pwd("PWD=");
		free(path);
		path = ft_get_key_value(ft_key_index("PWD="));
		ft_putendl_fd(path, 1);
		free(path);
	}
	else
	{
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
		g_env.g_status = 1;
	}
}

void	ft_chenge_dir(char *path)
{
	ft_chenge_pwd("OLDPWD=");
	ft_err_cd(chdir(path));
	ft_chenge_pwd("PWD=");
}

void	ft_cd(char *path)
{
	if (!path || !*path)
		ft_none_path();
	else if (!ft_strncmp(path, "-", ft_strlen(path)))
		ft_arg_minus();
	else
		ft_chenge_dir(path);
}
