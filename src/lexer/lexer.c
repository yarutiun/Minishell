/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:20:18 by hboichuk          #+#    #+#             */
/*   Updated: 2023/02/27 20:38:11 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//give type of token
void	get_type_tok(t_token *token_arr)
{
	t_token	*temp;

	temp = token_arr;
	printf("%s", token_arr->str);
	while (temp != NULL)
	{
		printf("%s", temp->str);
		if (temp->str[0] == '|')
			temp->tok_type = PIPE;
		else if (temp->str[0] == '>' && ft_strlen(temp->str) == 1)
			temp->tok_type = LESS_THAN;
		else if (temp->str[0] == '<' && ft_strlen(temp->str) == 1)
			temp->tok_type = GREATER_THAN;
		else if (temp->str[0] == '>' && ft_strlen(temp->str) == 1)
			temp->tok_type = LESS_THAN;
		else if ((temp->str[0] >= 33 && temp->str[0] <= 59) ||
		temp->str[0] == 61 || (temp->str[0] >= 63 && temp->str[0] <= 126))
			temp->tok_type = WORD;
		else
			temp->tok_type = SPACE;// the same?
		temp = temp->next;
	}
}

char	**split_arguments(char *string)
{
	char	*cutted_str;
	char	**tok_arr;
	
	cutted_str = ft_strtrim(string, " ");
	free(string);
	string = cutted_str;
	if (!string)
	{
		printf("nothing in line!");
		exit(0);
	}
	tok_arr = ft_split(cutted_str, ' ');
	return (tok_arr);
}

//we needs error_handler for lexer and so on 
t_token	*lexer(t_global *global)
{
	char	**arguments;
	int		i;
	t_token *token_list;

	i = 0;
	token_list = global->lexer_list;
	arguments = split_arguments(global->args);
	//test
	// while (arguments[i])
	// {
	// 	printf("%s", arguments[i]);
	// 	printf("\n");
	// 	i++;
	// }
	if(!arguments)
	{
		printf("can't split arguments");
	}
	token_list = fill_stack_tokens(arguments, token_list);
	//test
	// while (token_list->next != NULL)
	// {
	// 	printf("%s, %d, %d", token_list->str, token_list->index, token_list->tok_type);
	// 	printf("\n");
	// 	token_list = token_list->next;
	// 	i++;
	// }
	get_type_tok(token_list);
	return(token_list);
}
