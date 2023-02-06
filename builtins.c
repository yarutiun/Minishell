/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:02:36 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/06 12:22:46 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

//checks if the first element in the cmd_group full_cmd is a builtin
int	check_builtins(t_minishell *cmd_group)
{
	int	len_builtin;

	if (!cmd_group->builtin_cmd)
		return (0);
	if ((cmd_group->builtin_cmd && ft_strchr(*cmd_group->builtin_cmd, '/')) || \
		(cmd_group->cmd_path && ft_strchr(cmd_group->cmd_path, '/')))
		return (0);
	len_builtin = ft_strlen(cmd_group->builtin_cmd);
	if (!ft_strncmp(*cmd_group->builtin_cmd, "cd", len_builtin) && \
		len_builtin == 2)
		return (1);
	if (!ft_strncmp(*cmd_group->builtin_cmd, "pwd", len_builtin) && \
		len_builtin == 3)
		return (1);
	if (!ft_strncmp(*cmd_group->builtin_cmd, "env", len_builtin) && \
		len_builtin == 3)
		return (1);
	if (!ft_strncmp(*cmd_group->builtin_cmd, "echo", len_builtin) && \
		len_builtin == 4)
		return (1);
	if (!ft_strncmp(*cmd_group->builtin_cmd, "exit", len_builtin) && \
		len_builtin == 4)
		return (1);
	if (!ft_strncmp(*cmd_group->builtin_cmd, "unset", len_builtin) && \
		len_builtin == 5)
		return (1);
	if (!ft_strncmp(*cmd_group->builtin_cmd, "export", len_builtin) && \
		len_builtin == 6)
		return (1);
}

int	builtin_handler(t_minishell cmd_group, )