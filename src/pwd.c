/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:56:58 by hboichuk          #+#    #+#             */
/*   Updated: 2023/02/23 15:59:33 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	find_pwd(t_global	*minishell)
{
	int	i;

	i = 0;
	while (minishell->envp[i])
	{
		if (!ft_strncmp(minishell->envp[i], "PWD=", 4))
			minishell->pwd = ft_substr(minishell->envp[i],
					4, ft_strlen(minishell->envp[i]) - 4);
		if (!ft_strncmp(minishell->envp[i], "OLDPWD=", 7))
			minishell->old_pwd = ft_substr(minishell->envp[i],
					7, ft_strlen(minishell->envp[i]) - 7);
		i++;
	}
	return (1);
}
