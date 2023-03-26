/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:06:59 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/25 17:54:24 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	ft_pwd(void)
{
	int		j;
	char	*pwd;

	j = 0;
	j = find_path_env(g_shell_h->envp, "PWD");
	pwd = ft_strchr(g_shell_h->envp[j], '=');
	pwd++;
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
