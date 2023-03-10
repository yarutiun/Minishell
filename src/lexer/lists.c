/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:13:16 by hboichuk          #+#    #+#             */
/*   Updated: 2023/02/27 20:38:22 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

//create new list for each token
t_token	*create_new_list(char *data, int index)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new != 0)
	{
		new->str = data;
		new->index = index;
		new->tok_type = 0;
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}

//fill chain fo nodes by tokens
t_token	*fill_stack_tokens(char **argv, t_token *token_list)
{
	t_token	*temp;
	int		i;
	int		length;

	temp = NULL;
	length = 0;
	i = 0;
	while (argv[length])
		length++;
	while (i <= length)
	{
		if (token_list == NULL)
		{
			token_list = create_new_list(argv[i], i);
			// printf("%s, %d, %d", token_list->str, token_list->index, token_list->tok_type);
			// printf("\n");
			++i;
		}
		else
		{
			temp = token_list;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = create_new_list(argv[i], i);
			// printf("%s, %d, %d", token_list->str, token_list->index, token_list->tok_type);
			// printf("\n");
			temp->next->prev = temp;
		i++;
		}
	}
	return (token_list);
}
