/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:26:23 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/04 15:20:59 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/built.h"

/* The "env" built-in command is used to display the current environment
** variables. When env is called without any arguments, it will print out all
** of the environment variables that are currently set. */
int	ft_env(t_global *global, t_simple_cmds *simple_cmd)
{
	int	i;

	(void) simple_cmd;
	i = 0;
	while (global->envp[i])
	{
		ft_putendl_fd(global->envp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
