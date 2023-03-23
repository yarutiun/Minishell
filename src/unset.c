/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:49:09 by dsas              #+#    #+#             */
/*   Updated: 2023/03/23 17:52:17 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	b_unset(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = find_path_env(shell_h->envp, args[i]);
		if (j != -1 && shell_h->envp[j])
		{
			free(shell_h->envp[j]);
			shell_h->envp[j] = NULL;
		}
		else
		{
			ft_putstr_fd("minishell: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putstr_fd("': not a valid identifier\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
