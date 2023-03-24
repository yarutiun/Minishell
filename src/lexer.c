/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:46:14 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/24 19:54:18 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	cat_quote(char **splited, int *words, t_token **head)
{
	char	quote;
	t_token	*temp;

	temp = malloc(sizeof(t_token));
	temp->info = NULL;
	quote = splited[*words][0];
	(*words)--;
	while (*words >= 0 && splited[*words][0] != quote)
	{
		temp->info = ft_strjoin(splited[*words], temp->info);
		(*words)--;
	}
	free(splited[*words]);
	temp->len = ft_strlen(temp->info);
	if (quote == '\'')
		temp->type = SINGLE_QUOTES;
	else
		temp->type = DOUBLE_QUOTES;
	temp->next = *head;
	*head = temp;
	(*words)--;
}

int	check_for_closed_brackets(char **splited)
{
	int		quote;
	int		i;

	quote = 0;
	i = 0;
	while (splited[i])
	{
		if (quote)
		{
			if (quote == 1 && (strcmp(splited[i], "\'") == 0))
				quote = 0;
			else if (quote == 2 && (strcmp(splited[i], "\"") == 0))
				quote = 0;
		}
		else if ((strcmp(splited[i], "\'") == 0))
			quote = 1;
		else if ((strcmp(splited[i], "\"") == 0))
			quote = 2;
		i++;
	}
	if (quote)
		return (1);
	return (0);
}

int	init_list(t_token **head, char *split, char **splited)
{
	int		words;
	int		in_splited;
	t_token	*temp;

	if (check_for_closed_brackets(splited) == 1)
	{
		throw_error("minishell: brackets not closed\n");
		return (1);
	}
	in_splited = count_words(split);
	words = count_words(split);
	words -= 1;
	in_splited -= 2;
	while (0 <= words)
	{
		if (splited[words][0] == '\"' || splited[words][0] == '\'')
		{
			cat_quote(splited, &words, head);
			continue ;
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
	return (0);
}
