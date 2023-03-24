/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:26:23 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/24 11:37:24 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

/* The "env" built-in command is used to display the current environment
** variables. When env is called without any arguments, it will print out all
** of the environment variables that are currently set. */
int	ft_env(void)
{
	int	i;

	i = 0;

	while (shell_h->envp[i])
	{
		if (shell_h->envp[i] == NULL)
			continue;
		printf("%s\n", shell_h->envp[i]);
		i++;
	}
	return (0);
}

// int main(int argc, char **argv, char **envp)
// {
// 	assign_env(envp, &shell_h);
// 	ft_env();
// 	return(0);
// }
