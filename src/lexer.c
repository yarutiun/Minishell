/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:46:14 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/23 16:38:22 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

//initializes a list for tokens and fills info with actual simbols and words
//allocates memory for nodes

void cat_quote(char **splited, int *words, t_token **head)
{
	char quote;
	t_token *temp;

	temp = malloc(sizeof(t_token));
	temp->info = NULL;
	quote = splited[*words][0];
	(*words)--;
	while(*words >= 0 && splited[*words][0] != quote)
	{
		temp->info = ft_strjoin(splited[*words], temp->info);
		(*words)--;
	}
	free(splited[*words]);
	temp->len = ft_strlen(temp->info);
	if(quote == '\'')
		temp->type = SINGLE_QUOTES;
	else
		temp->type = DOUBLE_QUOTES;
	temp->next = *head;
	*head = temp;
	(*words)--;
}

void	init_list(t_token **head, char *split, char **splited)
{
	int		words;
	int		in_splited;
	t_token	*temp;

	// if(check_for_closed_brackets(splited) == 1) //if one of brackets not closed just exit programm
		// exit(EXIT_FAILURE);
	in_splited = count_words(split);
	words = count_words(split);
	words -= 1;
	in_splited -= 2;
	while (0 <= words)
	{
		if(splited[words][0] == '\"' || splited[words][0] == '\'')
		{
			cat_quote(splited, &words, head);
			continue;
		}
		temp = malloc(sizeof(t_token));
		temp->info = splited[words];
		temp->len = ft_strlen(splited[words]);
		temp->type = -1;
		temp->next = *head;
		*head = temp;
		words--;
		in_splited--;
	}
	free(splited);
}


//sets token types
void	put_type_tok(t_token **head)
{
	t_token	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (temp->type != -1)
		{
			temp = temp->next;
			continue;
		}
		if (temp->info[0] == '|')
			temp->type = PIPE;
		// else if (temp->info[0] == '\"')
		// 	temp->type = DOUBLE_quote_QUOTES;
		// else if (temp->info[0] == '\'')
		// 	temp->type = SINGLE_QUOTES;
		else if (temp->info[0] == '>' && temp->info[1] && temp->info[1] == '>')
			temp->type = APPEND;
		else if (temp->info[0] == '<' && temp->info[1] && temp->info[1] == '<')
			temp->type = HEREDOC;
		else if (temp->info[0] == '>')
			temp->type = GREATER_THAN;
		else if (temp->info[0] == '<')
			temp->type = LESS_THAN;
		else if ((temp->info[0] >= 33 && temp->info[0] <= 59) ||
		temp->info[0] == 61 || (temp->info[0] >= 63 && temp->info[0] <= 126))
			temp->type = WORD;
		else
			temp->type = SPACE;
		temp = temp->next;
	}
}

//returns 0 if all brackets are closed
//returns 1 if not and printf an error message
//this function will be called in "init_list" function
int check_for_closed_brackets(char **splited)
{
	int words;
	int double_quote;

	words = 0;
	while(splited[words])
	{
		double_quote = 0;
		while(splited[words][double_quote])
		{
			if(splited[words][double_quote] == '"')
			{
				double_quote += 1;
				while(splited[words][double_quote] != '\0')
				{
					if(splited[words][double_quote] == '"')
						break;
					double_quote ++;
					if(splited[words][double_quote] == '\0')
					{
						printf("Error: Brackets not closed");
						return(1);
					}
				}
			}
			double_quote++;
		}
		words++;
	}
	return(0);
}

t_token *new_token(int *i, char *info)
{
	t_token *new;

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

void find_tokens(t_token *temp)
{
	t_token *new;
	t_token *new_tok;
	t_token *new_struct;
	int i;

	i = 0;
	new_struct = new;
	new = malloc(sizeof(t_token));
	new->info = NULL;
	new->type = WORD;
	while (temp->info[i])
	{
		if (temp->info[i] == '<' || temp->info[i] == '>' || temp->info[i] == '|')
		{
			new->next = new_token(&i, temp->info);
			new_tok = new->next;
			new = malloc(sizeof(t_token));
			new_tok->next = new;
			new -> type = WORD;
			new -> info = NULL;
		}
		else
		{
			charjoin_free(&(new->info), temp->info[i]);
		}
	}
	new->next = temp->next;
	temp->next = new_struct;
}

void	split_words(t_token	**head)
{
	t_token *temp;

	temp = *head;
	while (temp)
	{
		if (temp->type == WORD)
		{
			find_tokens(&temp);
		}
	}
}
