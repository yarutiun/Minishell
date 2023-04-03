/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:46:14 by nrenz             #+#    #+#             */
/*   Updated: 2023/04/03 10:35:10 by yarutiun         ###   ########.fr       */
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
		strjoin_free(&(temp->info), splited[*words]);
		(*words)--;
	}
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
			if (quote == 1 && (ft_strcmp(splited[i], "\'") == 0))
				quote = 0;
			else if (quote == 2 && (ft_strcmp(splited[i], "\"") == 0))
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

void	temp_assign(t_token **temp, t_token **head, char **splited, int *words)
{
	*temp = malloc(sizeof(t_token));
	(*temp)->info = ft_strdup(splited[*words]);
	(*temp)->len = ft_strlen(splited[*words]);
	(*temp)->type = -1;
	(*temp)->next = *head;
	*head = *temp;
	(*words)--;
}

int	init_list(t_token **head, char *split, char **splited)
{
	int		words;
	t_token	*temp;

	if (check_for_closed_brackets(splited) == 1)
	{
		throw_error("minishell: brackets not closed\n");
		return (1);
	}
	words = count_words(split);
	words -= 1;
	while (0 <= words)
	{
		if (splited[words][0] == '\"' || splited[words][0] == '\'')
		{
			cat_quote(splited, &words, head);
			continue ;
		}
		temp_assign(&temp, head, splited, &words);
	}
	return (0);
}
