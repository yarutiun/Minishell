/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:40:04 by dsas              #+#    #+#             */
/*   Updated: 2023/03/24 16:40:07 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_handle);
}

void	child_sig(void)
{
	signal(SIGQUIT, sig_handle_child);
	signal(SIGINT, sig_handle_child);
}

void	heredoc_sig(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, heredoc_sig_handle);
}
