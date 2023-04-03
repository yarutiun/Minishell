/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:17:10 by yarutiun          #+#    #+#             */
/*   Updated: 2023/04/03 12:24:29 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	init_vars_env(int	*counter, char ***temp, int *i, char **envp)
{
	*counter = 0;
	*i = 0;
	g_shell_h = malloc(sizeof(t_minishell));
	while (envp[*counter])
		(*counter)++;
	*temp = malloc(sizeof(char *) * 1000);
	if (!(*temp))
		return ;
	while (*i < 1000)
	{
		(*temp)[*i] = NULL;
		(*i)++;
	}
	*i = 0;
}

int	assign_env(char **envp)
{
	int		counter;
	char	**temp;
	int		i;

	init_vars_env(&counter, &temp, &i, envp);
	while (i != counter)
	{
		temp[i] = strdup(envp[i]);
		if (!temp[i])
			return (0);
		i++;
	}
	envp[counter] = NULL;
	g_shell_h->envp = temp;
	g_shell_h->current_env = counter;
	g_shell_h->head = NULL;
	g_shell_h->pipes = NULL;
	g_shell_h->error = 0;
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
		temp->info = ft_itoa(g_shell_h->error);
		return ;
	}
	key = ft_substr(temp->info, 1, ft_strlen(temp->info) - 1);
	index = find_path_env(g_shell_h->envp, key);
	if (index == -1)
	{
		free(temp->info);
		free(key);
		temp->len = 0;
		temp->info = ft_strdup("");
		return ;
	}
	ret = cut_key(g_shell_h->envp, index, key);
	free(temp->info);
	free(key);
	temp->info = ret;
	temp->len = ft_strlen(ret);
}
