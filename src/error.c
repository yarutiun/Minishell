/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:56:50 by dsas              #+#    #+#             */
/*   Updated: 2023/04/03 12:28:33 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	throw_error(char *error)
{
	ft_putstr_fd(error, 2);
	free_t_pipe(&(g_shell_h->pipes));
	free_t_token(&(g_shell_h->head));
	return (1);
}

void	throw_error_exec(char *error)
{
	ft_putstr_fd(error, 2);
	g_shell_h->error = 127;
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		free(env[i]);
		i++;
	}
	free(env);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
