/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:26:23 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/21 15:09:27 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

/* The "env" built-in command is used to display the current environment
** variables. When env is called without any arguments, it will print out all
** of the environment variables that are currently set. */
// int	ft_env(t_minishell *global)
// {
// 	int	i;

// 	i = 0;
	
// 	while (global->envp[i])
// 	{
// 		printf("%s\n", global->envp[i]);
// 		i++;
// 	}
// 	return (EXIT_SUCCESS);
// }

// int main(int argc, char **argv, char **envp)
// {
// 	t_minishell global;
// 	assign_env(envp, &global);
// 	ft_env(&global);
// 	return(0);
// }