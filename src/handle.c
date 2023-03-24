/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:40:20 by dsas              #+#    #+#             */
/*   Updated: 2023/03/24 18:06:22 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	prompt(void)
{
	//ft_putstr_fd("minishell > ", 1);

}

void	sig_handle(int sig)
{
	if (sig == SIGINT)
	{
		// rl_replace_line("", 0);
		rl_on_new_line();
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_redisplay();
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
