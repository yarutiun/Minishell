/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:37:29 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/13 16:40:26 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	builtin_pwd(t_minishell *ms_data)
{
	char	cwd[256];

	getcwd(cwd, sizeof(cwd));
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*ms_data;

	ms_data = malloc(sizeof(t_minishell));
	builtin_pwd(ms_data);
	return (0);
}
