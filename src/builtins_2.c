/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:58:56 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/23 13:32:00 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

/* builtin export
   exports given argument to environment
   The correct syntax to assign and export a variable (with the assigned value) 
   at the same time is export NAME=value.
   tested, works :)
   too long function, needs to be split up!
*/
int	builtin_export(t_minishell *ms_data, t_minishell *shell_h)
{
	int	i;

	i = 0;
	if (!ms_data->builtin_cmd[1])
	{
		while (shell_h->envp[i])
		{
			printf("%s\n", shell_h->envp[i]);
			// printf("%d\n", i);
			i++;
		}
	}
	else
	{
		if (ft_strchr(ms_data->builtin_cmd[1], '='))
		{
			if (ms_data->builtin_cmd[2])
			{
				printf("minishell: export: too many arguments\n");
				return (0);
			}
			else
			{
				shell_h->envp = ft_calloc(2, sizeof(char *));
				shell_h->envp[i] = ft_strdup(ms_data->builtin_cmd[1]);
				shell_h->envp[i + 1] = NULL;
			}
		}
		else
		{
			printf("minishell: export: `%s': not a valid identifier\n", \
			ms_data->builtin_cmd[1]);
			return (0);
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*ms_data;
	t_minishell	*shell_h;

	ms_data = malloc(sizeof(t_minishell));
	shell_h = malloc(sizeof(t_minishell));
	shell_h->envp = envp;
	ms_data->builtin_cmd = argv;
	builtin_export(ms_data, shell_h);
	return (0);
}

/* builtin unset
   call the given argument back from environment
   tested, behavier not clear, not like bash
   too long function, needs to be split up!
*/
// int	builtin_unset(t_minishell *ms_data, t_minishell *shell_h)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (!ms_data->builtin_cmd[1])
// 	{
// 		printf("minishell: unset: not enough arguments\n");
// 		return (0);
// 	}
// 	else
// 	{
// 		while (shell_h->envp[i])
// 		{
// 			if (ft_strncmp(ms_data->builtin_cmd[1], shell_h->envp[i], \
// 			ft_strlen(ms_data->builtin_cmd[1])) == 0)
// 			{
// 				while (shell_h->envp[i + j])
// 				{
// 					shell_h->envp[i + j] = shell_h->envp[i + j + 1];
// 					j++;
// 				}
// 				shell_h->envp[i + j] = NULL;
// 				return (0);
// 			}
// 			i++;
// 		}
// 		printf("minishell: unset: `%s': not a valid identifier\n", \
// 		ms_data->builtin_cmd[1]);
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	t_minishell	*ms_data;
// 	t_minishell	*shell_h;

// 	(void)argc;
// 	(void)argv;
// 	ms_data = malloc(sizeof(t_minishell));
// 	shell_h = malloc(sizeof(t_minishell));
// 	shell_h->envp = envp;
// 	ms_data->builtin_cmd = ft_split("unset PATH", ' ');
// 	builtin_unset(ms_data, shell_h);
// 	return (0);
// }

/* builtin exit
   exits minishell with given argument or 0 if no argument is given
   tested, doens't work yet :(
*/
// int	builtin_exit(t_minishell *ms_data)
// {
// 	if (ms_data->builtin_cmd[1])
// 	{
// 		if (ft_isdigit(ms_data->builtin_cmd[1][0]))
// 		{
// 			if (ms_data->builtin_cmd[2])
// 			{
// 				printf("minishell: exit: too many arguments\n");
// 				return (0);
// 			}
// 			else
// 			{
// 				printf("exit\n");
// 				exit(ft_atoi(ms_data->builtin_cmd[1]));
// 			}
// 		}
// 		else
// 		{
// 			printf("minishell: exit: %s: numeric argument required\n", \
// 			ms_data->builtin_cmd[1]);
// 			return (0);
// 		}
// 	}
// 	else
// 	{
// 		printf("exit\n");
// 		exit(0);
// 	}
// 	return (0);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	t_minishell	*ms_data;
// 	t_minishell	*shell_h;

// 	(void)argc;
// 	(void)argv;
// 	ms_data = malloc(sizeof(t_minishell));
// 	shell_h = malloc(sizeof(t_minishell));
// 	shell_h->envp = envp;
// 	ms_data->builtin_cmd = ft_split("exit 1", ' ');
// 	builtin_exit(ms_data);
// 	return (0);
// }

