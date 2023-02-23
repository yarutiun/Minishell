/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:02:36 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/23 12:10:25 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

/* 	
	checks if the first element in the cmd_group is a builtin
	if it is, fill t_minihell variable 'cmds' with commands from our minishell input
*/
// void fill_builtin_cmd(t_token **head, t_minishell *cmds)
// {
// 	int len;
// 	t_token *temp;
// 	temp = *head;

// 	int i = 0;
// 	len = ft_lstsize_mod(temp);
//     cmds->builtin_cmd = malloc(sizeof(char *) * (len + 1));
// 	while(temp->next)
// 	{
// 		if(if_builtin(temp->info) == 1)
// 		{
// 			cmds->builtin_cmd[i] = malloc(sizeof(char *) * (ft_strlen(temp->info) + 1));
// 			ft_strcpy(cmds->builtin_cmd[i], temp->info); // segfault fixed
// 			i++;
// 		}
// 		temp = temp->next;
// 	}	      temp_pipe->builtin_cmd[i] = malloc(sizeof(char *) * (ft_strlen(temp_tok->info) + 1));
// }

/* checks if an input is a bash builtin */
int	if_builtin(char *word)
{
	int			len_builtin;

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
		return (1);
	return (0);
}
