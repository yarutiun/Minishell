/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:02:36 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/16 19:00:47 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

/* 	
	checks if the first element in the cmd_group is a builtin
	if it is, fill t_minihell variable 'cmds' with commands from our minishell input
*/
void	fill_builtin_cmd(t_token **head, t_minishell *ms_data)
{
	int		len;
	t_token	*temp;
	int		i;

	i = 0;
	temp = *head;
	len = ft_lstsize_mod(temp);
    ms_data->builtin_cmd = malloc(sizeof(char *) * len + 1);
	while (temp)
	{
		if (if_builtin(temp->info, ms_data) == 1)
		{
			ms_data->builtin_cmd[i] = malloc(sizeof(char *) * \
			ft_strlen(temp->info) + 1);
			ft_strcpy(ms_data->builtin_cmd[i], temp->info);
			i++;
		}
		temp = temp->next;
	}	
}

/* checks if an input is a bash builtin */
int	if_builtin(char *word, t_minishell *ms_data)
{
	int			len_builtin;

	len_builtin = ft_strlen(word);
	if (!ft_strncmp(word, "cd", len_builtin) && \
		len_builtin == 2)
		{
			builtin_cd(ms_data);
			return (1);
		}
	{
		builtin_cd(ms_data);
		return (1);
	}
	if (!ft_strncmp(word, "pwd", len_builtin) && \
		len_builtin == 3)
	{
		builtin_pwd(ms_data);
		return (1);
	}
	if (!ft_strncmp(word, "env", len_builtin) && \
		len_builtin == 3)
	{
		builtin_env(ms_data);
		return (1);
	}
	if (!ft_strncmp(word, "echo", len_builtin) && \
		len_builtin == 4)
		{
			builtin_echo(ms_data);
			return (1);
		}
	{
		builtin_echo(ms_data);
		return (1);
	}
	if (!ft_strncmp(word, "exit", len_builtin) && \
		len_builtin == 4)
	{
		builtin_exit(ms_data);
		return (1);
	}
	if (!ft_strncmp(word, "unset", len_builtin) && \
		len_builtin == 5)
	{
		builtin_unset(ms_data);
		return (1);
	}
	if (!ft_strncmp(word, "export", len_builtin) && \
		len_builtin == 6)
	{
		builtin_export(ms_data);
		return (1);
	}
	return (0);
}
