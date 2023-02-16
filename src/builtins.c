/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:02:36 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/16 16:13:57 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

//checks if the first element in the cmd_group full_cmd is a builtin
// int	check_builtins(t_minishell *cmd_group)
// {
// 	int	len_builtin;

// 	if (!cmd_group->builtin_cmd)
// 		return (0);
// 	if ((cmd_group->builtin_cmd && ft_strchr(word, '/')) || \
// 		(cmd_group->cmd_path && ft_strchr(cmd_group->cmd_path, '/')))
// 		return (0);
// 	len_builtin = ft_strlen(cmd_group->builtin_cmd);
// 	if (!ft_strncmp(, "cd", len_builtin) && \
// 		len_builtin == 2)
// 		return (1);
// 	if (!ft_strncmp(word, "pwd", len_builtin) && \
// 		len_builtin == 3)
// 		return (1);
// 	if (!ft_strncmp(word, "env", len_builtin) && \
// 		len_builtin == 3)
// 		return (1);
// 	if (!ft_strncmp(word, "echo", len_builtin) && \
// 		len_builtin == 4)
// 		return (1);
// 	if (!ft_strncmp(word, "exit", len_builtin) && \
// 		len_builtin == 4)
// 		return (1);
// 	if (!ft_strncmp(word, "unset", len_builtin) && \
// 		len_builtin == 5)
// 		return (1);
// 	if (!ft_strncmp(word, "export", len_builtin) && \
// 		len_builtin == 6)
// 		return (1);
// }

// int	builtin_handler(t_minishell cmd_group, )


// this command fills t_minihell variable 'cmds' with commands from our minishell input
void fill_builtin_cmd(t_token **head, t_minishell *cmds)
{
	int len;
	t_token *temp;
	temp = *head;

	int i = 0;
	len = ft_lstsize_mod(temp);
    cmds->builtin_cmd = malloc(sizeof(char *) * len + 1);
	while(temp)
	{
		if(if_builtin(temp->info) == 1)
		{
			cmds->builtin_cmd[i] = malloc(sizeof(char *) * ft_strlen(temp->info) + 1);
			ft_strcpy(cmds->builtin_cmd[i], temp->info); // segfault fixed
			i++;
		}
		temp = temp->next;
	}	
}

//checks if an input is a bash builtin
int if_builtin(char *word)
{
	int	len_builtin;
	len_builtin = ft_strlen(word);
	if (!ft_strncmp(word, "cd", len_builtin) && \
		len_builtin == 2)
		return (1);
	if (!ft_strncmp(word, "pwd", len_builtin) && \
		len_builtin == 3)
		return (1);
	if (!ft_strncmp(word, "env", len_builtin) && \
		len_builtin == 3)
		return (1);
	if (!ft_strncmp(word, "echo", len_builtin) && \
		len_builtin == 4)
		return (1);
	if (!ft_strncmp(word, "exit", len_builtin) && \
		len_builtin == 4)
		return (1);
	if (!ft_strncmp(word, "unset", len_builtin) && \
		len_builtin == 5)
		return (1);
	if (!ft_strncmp(word, "export", len_builtin) && \
		len_builtin == 6)
		return(1);
	return(0);
}

