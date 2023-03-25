/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:55:20 by dsas              #+#    #+#             */
/*   Updated: 2023/03/25 15:30:15 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	create_redirect(t_token **token, t_token **token_tmp,
					t_pipe_group **tmp, t_pipe_group **pipes)
{
	int	type;

	type = (*token_tmp)->type;
	skip_space(token_tmp);
	if (!(*token_tmp) || ((*token_tmp)->type != DOUBLE_QUOTES
			&& (*token_tmp)->type != SINGLE_QUOTES
			&& (*token_tmp)->type != WORD))
	{
		throw_error("minishell: syntax error near unexpected token\n");
		return ;
	}
	if (type == HEREDOC)
	{
		here_doc(token_tmp, tmp);
		return ;
	}
	if (type == LESS_THAN)
	{
		(*tmp)->input = open((*token_tmp)->info, O_RDONLY);
		if ((*tmp)->input < 0)
		{
			throw_error("minishell: couldn't open such file or directory\n");
			return ;
		}
	}
	else if (type == GREATER_THAN)
	{
		(*tmp)->output = open((*token_tmp)->info,
				O_WRONLY | O_TRUNC | O_CREAT, 0777);
		if ((*tmp)->output < 0)
		{
			throw_error("minishell: couldn't open such file or directory\n");
			return ;
		}
	}
	else if (type == APPEND)
	{
		(*tmp)->output = open((*token_tmp)->info,
				O_WRONLY | O_APPEND | O_CREAT, 0777);
		if ((*tmp)->output < 0)
		{
			throw_error("minishell: couldn't open such file or directory\n");
			return ;
		}
	}
	*token_tmp = (*token_tmp)->next;
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

t_pipe_group	*redirection(t_token **token)
{
	t_pipe_group	*tmp;
	t_token			*token_tmp;
	int				first;
	int				count_words;

	shell_h->pipes = init_pipe(0);
	tmp = shell_h->pipes;
	token_tmp = *token;
	first = 0;
	count_words = 0;
	while (token_tmp)
	{
		if ((token_tmp)->type == APPEND || (token_tmp)->type == HEREDOC
			|| (token_tmp)->type == GREATER_THAN
			|| (token_tmp)->type == LESS_THAN)
		{
			create_redirect(token, &token_tmp, &tmp, &(shell_h->pipes));
			if ((shell_h->pipes) == NULL)
				return (NULL);
		}
		else if ((token_tmp)->type == SINGLE_QUOTES
			|| (token_tmp)->type == DOUBLE_QUOTES
			|| (token_tmp)->type == WORD)
		{
			if (! (token_tmp->info))
			{
				token_tmp = token_tmp->next;
				continue ;
			}
			tmp->argv[count_words] = ft_strdup(token_tmp->info);
			if (!first)
			{
				tmp->cmd = tmp->argv[count_words];
				first = 1;
			}
			count_words++;
			token_tmp = token_tmp->next;
		}
		else if (token_tmp->type == PIPE)
		{
			if (!first)
			{
				throw_error("minishell: syntax error near unexpected token\n");
				return (NULL);
			}
			tmp->argv[count_words] = NULL;
			count_words = 0;
			first = tmp->pipe_index;
			token_tmp = token_tmp->next;
			tmp->next = init_pipe(first + 1);
			tmp = tmp->next;
			first = 0;
		}
		else
			token_tmp = token_tmp->next;
	}
	if (!first)
	{
		throw_error("minishell: syntax error near unexpected token\n");
		return (NULL);
	}
	tmp->argv[count_words] = NULL;
	return ((shell_h->pipes));
}
