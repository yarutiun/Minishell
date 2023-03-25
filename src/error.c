/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:56:50 by dsas              #+#    #+#             */
/*   Updated: 2023/03/25 16:12:51 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	throw_error(char *error)
{
	ft_putstr_fd(error, 2);
	free_t_pipe(&(shell_h->pipes));
	free_t_token(&(shell_h->head));
	return (1);
}

void	throw_error_exec(char *error)
{
	ft_putstr_fd(error, 2);
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
