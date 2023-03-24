/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:52:06 by dsas              #+#    #+#             */
/*   Updated: 2023/03/24 19:52:31 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	change_quotes(t_token *temp)
{
	char	*ret;
	char	*info;
	int		i;

	ret = NULL;
	info = temp->info;
	i = 0;
	while (info[i])
	{
		if (info[i] == '$' && (info[i + 1] != ' ' && info[i + 1] != '\0'))
		{
			sub_dollar(&ret, info, &i);
		}
		else
		{
			charjoin_free(&ret, info[i]);
			i++;
		}
	}
	free(temp->info);
	temp->info = ret;
	temp->len = ft_strlen(ret);
}

void	expander(t_token **token)
{
	t_token	*temp;
	int		index;
	char	*key;
	char	*ret;

	temp = *token;
	while (temp)
	{
		if (temp->type == WORD && temp->info
			&& temp->info[0] == '$' && temp->info[1])
			change_words(temp);
		if (temp->type == DOUBLE_QUOTES)
			change_quotes(temp);
		temp = temp->next;
	}
}
