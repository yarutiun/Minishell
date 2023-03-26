/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:55:20 by dsas              #+#    #+#             */
/*   Updated: 2023/03/25 17:57:02 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	open_output(t_pipe_group **tmp, t_token **token_tmp, int type)
{
	if (type == APPEND)
		(*tmp)->output = open((*token_tmp)->info,
				O_WRONLY | O_APPEND | O_CREAT, 0777);
	else
		(*tmp)->output = open((*token_tmp)->info,
				O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if ((*tmp)->output < 0)
		return (1);
	return (0);
}

int	create_red(t_token **token_tmp,
					t_pipe_group **tmp)
{
	int	type;

	type = (*token_tmp)->type;
	skip_space(token_tmp);
	if (!(*token_tmp) || ((*token_tmp)->type != DOUBLE_QUOTES
			&& (*token_tmp)->type != SINGLE_QUOTES
			&& (*token_tmp)->type != WORD))
		return (throw_error(SYNTAX_ERROR));
	if (type == HEREDOC)
		return (here_doc(token_tmp, tmp));
	if (type == LESS_THAN)
	{
		(*tmp)->input = open((*token_tmp)->info, O_RDONLY);
		if ((*tmp)->input < 0)
			return (throw_error(OPEN_ERROR));
	}
	else if (type == GREATER_THAN || type == APPEND)
	{
		if (open_output(tmp, token_tmp, type))
			return (throw_error(OPEN_ERROR));
	}
	*token_tmp = (*token_tmp)->next;
	return (0);
}

t_pipe_group	*init_pipe(int index)
{
	t_pipe_group	*pipe;
	int				i;

	i = 0;
	pipe = malloc (sizeof(t_pipe_group));
	pipe->argv = malloc(sizeof(char *) * 50);
	while (i < 50)
	{
		pipe->argv[i] = NULL;
		i++;
	}
	pipe->cmd = NULL;
	pipe->heredoc = NULL;
	pipe->input = -1;
	pipe->output = -1;
	pipe->next = NULL;
	pipe->pipe_index = index;
	return (pipe);
}

int	quote_if(t_pipe_group **tmp, t_token **token_tmp,
						int *first, int *count_words)
{
	if (!((*token_tmp)->info))
	{
		*token_tmp = (*token_tmp)->next;
		return (1);
	}
	(*tmp)->argv[*count_words] = ft_strdup((*token_tmp)->info);
	if (!(*first))
	{
		(*tmp)->cmd = (*tmp)->argv[*count_words];
		*first = 1;
	}
	(*count_words)++;
	*token_tmp = (*token_tmp)->next;
	return (0);
}

int	pipe_if(t_pipe_group **tmp, t_token **token_tmp,
			int *first, int *count_words)
{
	if (!(*first))
		return (1);
	(*tmp)->argv[*count_words] = NULL;
	*count_words = 0;
	*first = (*tmp)->pipe_index;
	*token_tmp = (*token_tmp)->next;
	(*tmp)->next = init_pipe(*first + 1);
	*tmp = (*tmp)->next;
	*first = 0;
	return (0);
}
