/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:58:07 by yarutiun          #+#    #+#             */
/*   Updated: 2023/03/06 21:04:39 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/built.h"

/* This function updates the "PWD" and "OLDPWD" environment variables in the
** global environment variable array. It searches for "PWD=" and "OLDPWD="
** strings in the array, and replaces their values with the current working
** directory (stored in global->pwd) and the previous working directory
** (stored in global->old_pwd), respectively. */
void	update_env_path(t_global *global)
{
	char	*buff;
	int		i;

	i = 0;
	while (global->envp[i])
	{
		if (!ft_strncmp(global->envp[i], "PWD=", 4))
		{
			buff = ft_strjoin("PWD=", global->pwd);
			free(global->envp[i]);
			global->envp[i] = buff;
		}
		else if (!ft_strncmp(global->envp[i], "OLDPWD=", 7) && global->old_pwd)
		{
			buff = ft_strjoin("OLDPWD=", global->old_pwd);
			free(global->envp[i]);
			global->envp[i] = buff;
		}
		i++;
	}
}

int	ft_cd(t_global *global, t_simple_cmds *simple_cmd)
{
	int	out;

	if (!simple_cmd->str[1])
		out = get_special_path(global, "HOME=");
	else if (ft_strncmp(simple_cmd->str[1], "-", 1) == 0)
		out = get_special_path(global, "OLDPWD=");
	else
	{
		out = chdir(simple_cmd->str[1]);
		if (out != 0)
		{
			ft_putstr_fd("42minishell: ", 2);
			ft_putstr_fd(simple_cmd->str[1], 2);
			perror(" ");
		}
	}
	if (out != 0)
		return (EXIT_FAILURE);
	new_path(global);
	update_env_path(global);
	return (0);
}
