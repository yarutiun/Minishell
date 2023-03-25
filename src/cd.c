/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:22:39 by dsas              #+#    #+#             */
/*   Updated: 2023/03/25 17:49:15 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	change_dir(char *arg)
{
	char	*sub;
	char	*temp;
	int		i;
	char	*str1;
	char	*str2;

	sub = getcwd(0, 256);
	if (chdir(arg) == -1)
		return (-1);
	temp = getcwd(0, 256);
	str1 = ft_strjoin("OLDPWD=", sub);
	str2 = ft_strjoin("PWD=", temp);
	i = find_path_env(g_shell_h->envp, "OLDPWD");
	if (i != -1)
		g_shell_h->envp[i] = ft_strdup(str1);
	else
		set_new(str1);
	i = find_path_env(g_shell_h->envp, "PWD");
	if (i != -1)
		g_shell_h->envp[i] = ft_strdup(str2);
	else
		set_new(str2);
	free(sub);
	free(temp);
	return (1);
}

int	b_cd(char *arg)
{
	if (!arg)
	{
		if (change_dir(cut_key(g_shell_h->envp,
					find_path_env(g_shell_h->envp, "HOME"), "HOME")) == -1)
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	}
	else
	{
		if (change_dir(arg) == -1)
		{
			ft_putstr_fd("cd: no such file or directory: ", 2);
			ft_putstr_fd(arg, 2);
			ft_putstr_fd("\n", 2);
			return (1);
		}
	}
	return (0);
}
