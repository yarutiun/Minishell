/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:54:24 by dsas              #+#    #+#             */
/*   Updated: 2023/03/25 17:07:32 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	put_type_tok(t_token **head)
{
	t_token	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (put_skip(&temp))
			continue ;
		if (temp->info[0] == '|' && !(temp->info[1]))
			temp->type = PIPE;
		else if (temp->info[0] == '>' && temp->info[1]
			&& temp->info[1] == '>' && !(temp->info[2]))
			temp->type = APPEND;
		else if (temp->info[0] == '<' && temp->info[1]
			&& temp->info[1] == '<' && !(temp->info[2]))
			temp->type = HEREDOC;
		else if (temp->info[0] == '>' && !(temp->info[1]))
			temp->type = GREATER_THAN;
		else if (temp->info[0] == '<' && !(temp->info[1]))
			temp->type = LESS_THAN;
		else if (temp->info[0] != ' ')
			temp->type = WORD;
		else
			temp->type = SPACE;
		temp = temp->next;
	}
}

t_token	*new_token(int *i, char *info)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	new->info = NULL;
	if (info[*i] == '|')
		new->type = PIPE;
	else if (info[*i] == '>' && info[(*i) + 1] && info[(*i) + 1] == '>')
	{
		new->type = APPEND;
		(*i) += 2;
		return (new);
	}
	else if (info[(*i)] == '<' && info[(*i) + 1] && info[(*i) + 1] == '<')
	{
		new->type = HEREDOC;
		(*i) += 2;
		return (new);
	}
	else if (info[(*i)] == '>')
		new->type = GREATER_THAN;
	else if (info[(*i)] == '<')
		new->type = LESS_THAN;
	(*i)++;
	return (new);
}

void	split_words(t_token	**head)
{
	t_token	*temp;

	temp = *head;
	while (temp)
	{
		if (temp->type == WORD)
		{
			find_tokens(&temp);
			continue ;
		}
		temp = temp->next;
	}
}

void	find_tokens_loop(t_token **temp, t_token **new, t_token **new_tok)
{
	int	i;

	i = 0;
	while ((*temp)->info[i])
	{
		if ((*temp)->info[i] == '<' || (*temp)->info[i] == '>'
			|| (*temp)->info[i] == '|')
		{
			(*new)->next = new_token(&i, (*temp)->info);
			(*new_tok) = (*new)->next;
			(*new_tok)->next = malloc(sizeof(t_token));
			(*new) = (*new_tok)->next;
			(*new)->type = WORD;
			(*new)->info = NULL;
			continue ;
		}
		else
		{
			charjoin_free(&((*new)->info), (*temp)->info[i]);
		}
		i++;
	}
}

void	find_tokens(t_token **temp)
{
	t_token	*new;
	t_token	*new_tok;
	t_token	*new_struct;

	new = malloc(sizeof(t_token));
	new_struct = new;
	new->info = NULL;
	new->type = WORD;
	find_tokens_loop(temp, &new, &new_tok);
	free((*temp)->info);
	(*temp)->info = NULL;
	new->next = (*temp)->next;
	(*temp)->next = new_struct;
	(*temp) = new->next;
}
