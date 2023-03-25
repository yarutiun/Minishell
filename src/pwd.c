/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:06:59 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/25 17:51:49 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	ft_pwd(void)
{
	int		i;
	int		j;
	char	*pwd;

	i = 0;
	j = 0;
	j = find_path_env(g_shell_h->envp, "PWD");
	pwd = ft_strchr(g_shell_h->envp[j], '=');
	pwd++;
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	return (1);
}
