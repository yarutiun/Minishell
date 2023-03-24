/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:17:10 by yarutiun          #+#    #+#             */
/*   Updated: 2023/03/24 19:51:58 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	assign_env(char **envp, t_minishell **shell_h)
{
	int		counter;
	int		len;
	char	**temp;
	int		i;

	counter = 0;
	i = 0;
	*shell_h = malloc(sizeof(t_minishell));
	if (!(*shell_h))
		return (0);
	while (envp[counter])
		counter++;
	temp = malloc(sizeof(char *) * 1000);
	if (!temp)
		return (0);
	while (i < 1000)
	{
		temp[i] = NULL;
		i++;
	}
	i = 0;
	while (i != counter)
	{
		temp[i] = strdup(envp[i]);
		if (!temp[i])
			return (0);
		i++;
	}
	envp[counter] = NULL;
	(*shell_h)->envp = temp;
	(*shell_h)->current_env = counter;
	(*shell_h)->head = NULL;
	(*shell_h)->pipes = NULL;
	return (1);
}

void	strjoin_free(char **str, char *add)
{
	char	*res;

	res = ft_strjoin(*str, add);
	free(*str);
	*str = res;
}

void	charjoin_free(char **str, char add)
{
	char	*res;
	char	*adder;

	adder = malloc(2);
	adder[1] = 0;
	adder[0] = add;
	res = ft_strjoin(*str, adder);
	free(*str);
	free(adder);
	*str = res;
}

void	change_words(t_token *temp)
{
	int		index;
	char	*key;
	char	*ret;

	if (temp->info[1] == '?' && (!(temp->info[2]) || temp->info[2] == ' '))
	{
		free(temp->info);
		temp->info = ft_itoa(shell_h->error);
		return ;
	}
	key = ft_substr(temp->info, 1, ft_strlen(temp->info) - 1);
	index = find_path_env(shell_h->envp, key);
	if (index == -1)
	{
		free(temp->info);
		free(key);
		temp->len = 0;
		temp->info = ft_strdup("");
		return ;
	}
	ret = cut_key(shell_h->envp, index, key);
	free(temp->info);
	free(key);
	temp->info = ret;
	temp->len = ft_strlen(ret);
}

void	sub_dollar(char **ret, char *info, int *i)
{
	char	*key;
	int		index;
	char	*ret1;

	key = NULL;
	(*i)++;
	if (info[*i] == '?' && (!(info[*i]) || info[*i + 1] == ' '))
	{
		strjoin_free(ret, ft_itoa(shell_h->error));
	}
	while (info[*i] != ' ' && info[*i] != '\0')
	{
		charjoin_free(&key, info[*i]);
		(*i)++;
	}
	index = find_path_env(shell_h->envp, key);
	if (index == -1)
	{
		free(key);
		return ;
	}
	ret1 = cut_key(shell_h->envp, index, key);
	free(key);
	strjoin_free(ret, ret1);
	free(ret1);
}
