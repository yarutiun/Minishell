/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:46:14 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/18 17:46:40 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	init_list(t_token **head, char *split, char **splited)
{
	int		words;
	int		in_splited;
	int		counter;
	t_token	*temp;
	
	if(check_for_closed_brackets(splited) == 1)
			exit(EXIT_FAILURE);
	counter = 0;
	in_splited = count_words(split);
	words = count_words(split);
	words -= 1;
	in_splited -= 2;
	while (counter < words)
	{
		temp = malloc(sizeof(t_token));
		temp->info = splited[in_splited];
		temp->len = 0;
		temp->type = 0;
		temp->next = *head;
		*head = temp;
		words--;
		in_splited--;
	}
}

void	put_type_tok(t_token **head)
{
	t_token	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (temp->info[0] == '|')
			temp->type = PIPE;
		else if (temp->info[0] == '>')
			temp->type = LESS_THAN;
		else if (temp->info[0] == '<')
			temp->type = GREATER_THAN;
		else if (temp->info[0] == '>')
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
	int chars;

	words = 0;
	while(splited[words])
	{
		chars = 0;
		while(splited[words][chars])
		{
			if(splited[words][chars] == '"')
			{
				chars += 1;
				while(splited[words][chars] != '\0')
				{
					if(splited[words][chars] == '"')
						break;
					chars ++;
					if(splited[words][chars] == '\0')
					{
						printf("Error: Brackets not closed");
						return(1);
					}
				}
			}
			chars++;
		}
		words++;
	}
	return(0);
}

//returns 0 if initialization was dumped
int init_all(t_token **token, t_minishell *globals, char *split, char **splited, char **envp)
{
	init_list(token, split, splited);
	if(assign_env(envp, globals) == 0)
		return(0);
	fill_builtin_cmd(token, globals);
	globals->pid = 0;
	globals->error = 0;
	globals->cmd_path = NULL;
	return(1);
}