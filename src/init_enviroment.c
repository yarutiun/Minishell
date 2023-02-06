/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enviroment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:16:26 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/06 18:28:47 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

t_minishell	*new_envp(t_minishell *ms_data)
{
	t_minishell	*new;

	new = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
	if (!new)
		return (NULL);
	new->key = ft_strdup(ms_data->key);
	new->value = ft_strdup(ms_data->value);
	new->next = NULL;
	return (new);
}

t_minishell	*add_back_envp(t_minishell *ms_data)
{
	t_minishell	*temp;

	if (!ms_data->head || !ms_data->new)
		return (NULL);
	else
	{
		temp = ms_data->head;
		while (temp->next)
			temp = temp->next;
		temp->next = ms_data->new;
	}
	return (ms_data->head);
}

void	init_envp(t_minishell *ms_data)
{
	int	i;

	i = 0;
	while (ms_data->envp[i])
	{
		ms_data->key = ft_substr(ms_data->envp[i], 0, \
						ft_strchr(ms_data->envp[i], '=') - ms_data->envp[i]);
		ms_data->value = ft_strdup(ft_strchr(ms_data->envp[i], '=') + 1);
		ms_data->new = new_envp(ms_data->key, ms_data->value);
		add_back_envp(ms_data->head, ms_data->new);
		i++;
	}
}

int	print_envp(t_minishell *ms_data)
{
	while (ms_data->head)
	{
		printf("%s=%s\n", ms_da->head->key, ms_data->head->value);
		head = ms_data->head->next;
	}
	return (0);
}
