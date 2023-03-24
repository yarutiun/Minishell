/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:24:25 by dsas              #+#    #+#             */
/*   Updated: 2023/03/24 14:23:10 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void free_t_token(t_token **token)
{
	t_token	*tmp;
	t_token	*next;

	if (!token)
		return ;
	tmp = *token;
	while(tmp)
	{
		next = tmp->next;
		free(tmp->info);
		free(tmp);
		tmp = next;
	}
	*token = NULL;
}

void free_t_pipe(t_pipe_group **token)
{
	t_pipe_group	*tmp;
	t_pipe_group	*next;

	if (!token)
		return ;
	tmp = *token;
	while(tmp)
	{
		next = tmp->next;
		ft_free_strings(tmp->argv);
		if (tmp->heredoc)
			unlink(tmp->heredoc);
		free(tmp->heredoc);
		free(tmp);
		tmp = next;
	}
	*token = NULL;
}

void	free_shell_h()
{
	int	i;

	i = 0;
	free_t_pipe(shell_h->pipes);
	free_t_token(shell_h->head);
	while (i < shell_h->current_env)
	{
		free(shell_h->envp[i]);
		i++;
	}
	free(shell_h->envp);
	free(shell_h);
	clear_history();
}
