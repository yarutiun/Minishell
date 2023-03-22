/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:58:07 by yarutiun          #+#    #+#             */
/*   Updated: 2023/03/22 09:18:37 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

/* This function updates the "PWD" and "OLDPWD" environment variables in the
** shell_h environment variable array. It searches for "PWD=" and "OLDPWD="
** strings in the array, and replaces their values with the current working
** directory (stored in shell_h->pwd) and the previous working directory
** (stored in shell_h->old_pwd), respectively. */
void	update_env_path(void)
{
	char	*buff;
	int		i;

	i = 0;
	while (shell_h->envp[i])
	{
		if (!ft_strncmp(shell_h->envp[i], "PWD=", 4))
		{
			buff = ft_strjoin("PWD=", shell_h->pwd);
			free(shell_h->envp[i]);
			shell_h->envp[i] = buff;
		}
		else if (!ft_strncmp(shell_h->envp[i], "OLDPWD=", 7) && shell_h->old_pwd)
		{
			buff = ft_strjoin("OLDPWD=", shell_h->old_pwd);
			free(shell_h->envp[i]);
			shell_h->envp[i] = buff;
		}
		i++;
	}
}

int	ft_cd(t_shell_h *shell_h, t_simple_cmds *simple_cmd)
{
	int	out;

	if (!simple_cmd->str[1])
		out = get_special_path(shell_h, "HOME=");
	else if (ft_strncmp(simple_cmd->str[1], "-", 1) == 0)
		out = get_special_path(shell_h, "OLDPWD=");
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
	new_path(shell_h);
	update_env_path(shell_h);
	return (0);
}
