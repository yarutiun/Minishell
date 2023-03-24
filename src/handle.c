/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:40:20 by dsas              #+#    #+#             */
/*   Updated: 2023/03/24 16:43:51 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	prompt(void)
{
	ft_putstr_fd("minishell > ", 1);
}

void	sig_handle(int sig)
{
	if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		prompt();
	}
}

void	sig_handle_child(int sig)
{
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
	}
	if (sig == SIGINT)
		ft_putchar_fd('\n', STDOUT_FILENO);
}

void	heredoc_sig_handle(int sig)
{
	if (sig == SIGINT)
	{
		exit(EXIT_FAILURE);
	}
}
