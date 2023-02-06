/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enviroment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:16:26 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/06 15:50:56 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

t_minishell	*new_envp(char *key, char *value)
{
	t_minishell	*new;

	new = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

t_minishell	*add_back_envp(t_minishell **head, t_minishell *new)
{
	t_minishell	*tmp;

	if (!head || !new)
		return (NULL);
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (*head);
}

void	init_envp(t_minishell **input, char **envp)
{
	t_minishell	*new;
	char	*key;
	char	*value;
	int		i;

	i = 0;
	while (envp[i])
	{
		key = ft_substr(envp[i], 0, ft_strchr(envp[i], '=') - envp[i]);
		value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		new = new_envp(key, value);
		add_back_envp(input, new);
		i++;
	}
}

void	print_envp(t_minishell *head)
{
	while (head)
	{
		printf("%s=%s\n", head->key, head->value);
		head = head->next;
	}
}
