/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:52:06 by dsas              #+#    #+#             */
/*   Updated: 2023/04/03 10:38:08 by yarutiun         ###   ########.fr       */
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
	if (!info)
		return ;
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

void	free_in_sub(char *ret1, char *key)
{
	free(key);
	free(ret1);
}

void	sub_dollar(char **ret, char *info, int *i)
{
	char	*key;
	int		index;
	char	*ret1;

	key = NULL;
	(*i)++;
	if (info[*i] == '?' && (!(info[*i + 1]) || info[*i + 1] == ' ' \
	|| info[*i + 1] == '\'' || info[*i + 1] == '\"'))
		strjoin_free(ret, ft_itoa(g_shell_h->error));
	while (info[*i] != ' ' && info[*i] != '\0' \
	&& info[*i] != '\'' && info[*i] != '\"')
	{
		charjoin_free(&key, info[*i]);
		(*i)++;
	}
	(*i)++;
	index = find_path_env(g_shell_h->envp, key);
	if (index == -1)
	{
		free(key);
		return ;
	}
	ret1 = cut_key(g_shell_h->envp, index, key);
	strjoin_free(ret, ret1);
	free_in_sub(ret1, key);
}
