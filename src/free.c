/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:24:25 by dsas              #+#    #+#             */
/*   Updated: 2023/03/24 13:43:53 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void free_t_token(t_token **token)
{
	t_token	*tmp;
	t_token	*next;

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
	while (i < shell_h->current_env)
	{
		free(shell_h->envp[i]);
		i++;
	}
	free(shell_h->envp);
}
