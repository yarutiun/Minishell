/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:43:22 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/18 17:18:55 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

/*	check if there are arguments
	if there are, call to chdir
	check if there is an error
*/
// int	builtin_cd(t_minishell *ms_data)
// {
// 	int		i;
// 	char	*home;

// 	i = 0;
// 	if (ms_data->args[1] == NULL)
// 	{
// 		while (ms_data->envp[i] != NULL)
// 		{
// 			if (ft_strncmp(ms_data->envp[i], "HOME=", 5) == 0)
// 				break ;
// 			i++;
// 		}
// 		home = ft_substr(ms_data->envp[i], 5, ft_strlen(ms_data->envp[i]));
// 		chdir(home);
// 	}
// 	else if (chdir(ms_data->args[1]) == -1)
// 	{
// 		printf("minishell: cd: %s: No such file or directory\n", \
// 		ms_data->args[1]);
// 		return (1);
// 	}
// 	return (0);
// }

// /*	
// 	check if the first argument is pwd
// 	if it is pwd, we need to print the current working directory
// 	if there are more arguments, we need to print an error message
// */
// int	builtin_pwd(t_minishell *ms_data)
// {
// 	char	cwd[256];

// 	getcwd(cwd, sizeof(cwd));
// 	ft_putstr_fd(cwd, 1);
// 	ft_putstr_fd("\n", 1);
// 	return (0);
// }

// /*
// 	check if the first argument is exit
// 	if it is exit, we need to exit the programm
// */
// int	builtin_exit(t_minishell *ms_data)
// {
// 	exit(0);
// 	return (0);
// }
