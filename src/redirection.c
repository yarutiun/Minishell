/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:19:38 by dsas              #+#    #+#             */
/*   Updated: 2023/03/22 15:26:49 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	skip_space(t_token **token)
{
	*token = (*token)->next;
	while ((*token)->type == SPACE)
		*token = (*token)->next;
}

void	here_doc(t_token **token, t_token **token_tmp, t_pipe_group **tmp, t_pipe_group **pipes)
{
	int		file;
	char	*buf;
	char	*limiter;
	char	*file_name;

	file_name = ft_strdup(".here_doc");
	charjoin_free(file_name, (*tmp) -> pipe_index + '0');
	limiter = (*token_tmp)->info;
	file = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
	{
		// free_tokens(token);
		// free_pipes(pipes);
		*token = NULL;
		*tmp = NULL;
		return ;
	}
	while (1)
	{
		buf = readline("> ");
		if (!buf)
			return(-1);
		if (!ft_strncmp(limiter, buf, ft_strlen(limiter)))
			break ;
		write(file, buf, ft_strlen(buf));
	}
	free(buf);
	close(file);
	(*tmp)->input = open(file_name, O_RDONLY);
	(*tmp)->heredoc = file_name;
	*token_tmp = (*token_tmp)->next;
}

void	create_redirect(t_token **token, t_token **token_tmp, t_pipe_group **tmp, t_pipe_group **pipes)
{
	int	type = (*token_tmp)->type;
	skip_space(token_tmp);
	if ((*token_tmp)->type == HEREDOC)
	{
		here_doc(token, token_tmp, tmp, pipes);
		return ;
	}
	if ((*token_tmp)->type != DOUBLE_QUOTES || (*token_tmp)->type != SINGLE_QUOTES || (*token_tmp)->type != WORD)
	{
		// free_tokens(token);
		// free_pipes(pipes);
		*token = NULL;
		*tmp = NULL;
		return ;
	}
	if (type == LESS_THAN)
		(*tmp)->input = open((*token_tmp)->info, O_RDONLY);
	else if (type == GREATER_THAN)
		(*tmp)->output = open((*token_tmp)->info, O_WRONLY | O_TRUNC);
	else if (type == APPEND)
		(*tmp)->output = open((*token_tmp)->info, O_WRONLY | O_APPEND);
	*token_tmp = (*token_tmp)->next;
}

void redirection(t_token **token)
{
	t_pipe_group *pipes;
	t_pipe_group *tmp;
	t_token		 *token_tmp;
	int			 first;

	pipes = malloc(sizeof(t_pipe_group));
	tmp = pipes;
	token_tmp = *token;
	while (token_tmp)
	{
		if ((token_tmp)->type == APPEND || (token_tmp)->type == HEREDOC
			|| (token_tmp)->type == GREATER_THAN || (token_tmp)->type == LESS_THAN )
		{
			create_redirect(token, &token_tmp, &tmp, &pipes);
		}
		else if ((token_tmp)->type == SINGLE_QUOTES || (token_tmp)->type == DOUBLE_QUOTES
			|| (token_tmp)->type == WORD)
		{

		}
	}
}
