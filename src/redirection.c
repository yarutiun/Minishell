/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:19:38 by dsas              #+#    #+#             */
/*   Updated: 2023/04/03 10:32:31 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	skip_space(t_token **token)
{
	*token = (*token)->next;
	while ((*token) && ((*token)->type == SPACE
			|| ((*token)->type == WORD && !((*token)->info))))
		*token = (*token)->next;
}

char	*here_doc_init(char **file_name, t_token **token_tmp,
						t_pipe_group **tmp, int *file)
{
	char	*limiter;

	*file_name = ft_strdup(".here_doc");
	charjoin_free(file_name, (*tmp)->pipe_index + '0');
	limiter = (*token_tmp)->info;
	*file = open(*file_name, O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	return (limiter);
}

void	here_doc_finish(t_token **token_tmp,
						t_pipe_group **tmp, char **file_name, char **buf)
{
	free(*buf);
	(*tmp)->input = open(*file_name, O_RDONLY);
	(*tmp)->heredoc = *file_name;
	*token_tmp = (*token_tmp)->next;
}

int	here_doc(t_token **token_tmp, t_pipe_group **tmp)
{
	int		file;
	char	*buf;
	char	*limiter;
	char	*file_name;

	limiter = here_doc_init(&file_name, token_tmp, tmp, &file);
	if (file < 0)
		return (throw_error("minishell: couldn't open HEREDOC\n"));
	while (1)
	{
		buf = readline("> ");
		charjoin_free(&buf, '\n');
		if (!buf)
		{
			free(buf);
			return (1);
		}
		if (!ft_strncmp(limiter, buf, ft_strlen(buf) - 1))
			break ;
		write(file, buf, ft_strlen(buf));
		free(buf);
	}
	close(file);
	here_doc_finish(token_tmp, tmp, &file_name, &buf);
	return (0);
}
