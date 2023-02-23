/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:57:16 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/23 10:12:14 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

/* 	extra function for builtin cd
	so you can get HOME path
*/
char	*get_env_var(char *var, t_minishell *shell_h)
{
	int	i;

	i = 0;
	while (shell_h->envp[i])
	{
		if (ft_strncmp(shell_h->envp[i], var, ft_strlen(var)) == 0)
			return (shell_h->envp[i] + ft_strlen(var));
		i++;
	}
	return (NULL);
}

/* 	builtin cd
	changes directory to HOME if no argument is given
	changes directory to given argument if one is given
	tested, works :)
*/
int	builtin_cd(t_minishell *ms_data, t_minishell *shell_h)
{
	int	i;

	i = 0;
	if (!ms_data->builtin_cmd[1])
	{
		chdir(get_env_var("HOME=", shell_h));
	}
	if (ms_data->builtin_cmd[2])
	{
		printf("minishell: cd: too many arguments\n");
		// g_status = 1;
		return (0);
	}
	if (chdir(ms_data->builtin_cmd[1]) == -1)
	{
		printf("minishell: cd: %s: No such file or directory\n", \
		ms_data->builtin_cmd[1]);
		// g_status = 1;
		return (0);
	}
	// else
	// 	g_status = 0;
	return (0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	t_minishell	*ms_data;
// 	t_minishell	*shell_h;

// 	(void)argc;
// 	(void)argv;
// 	ms_data = malloc(sizeof(t_minishell));
// 	shell_h = malloc(sizeof(t_minishell));
// 	shell_h->envp = envp;
// 	ms_data->builtin_cmd = argv;
// 	builtin_cd(ms_data, shell_h);
// 	return (0);
// }

/* 	builtin pwd 
	printd current working directory to STDOUT
	tested, works :)
*/
int	builtin_pwd(int fd)
{
	if (!getcwd(pwd, MAX_PWD))
	{
		perror("pwd");
		return (0);
	}
	ft_putstr_fd(pwd, fd);
	ft_putstr_fd("\n", fd);
	g_status = 0;
	return (0);
}

/* 	builtin pwd optinal function
	prints current working directory to terminal
	tested, works :)
*/
int	builtin_pwd(t_minishell *ms_data)
{
	char	cwd[256];

	getcwd(cwd, sizeof(cwd));
	ft_putstr_fd(cwd, 1);
	ft_putstr_fd("\n", 1);
	return (0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	t_minishell	*ms_data;

// 	ms_data = malloc(sizeof(t_minishell));
// 	builtin_pwd(ms_data);
// 	return (0);
// }

/* 	builtin envp 
	prints all environment variables to STDOUT
	tested, doesn't work yet :(
*/
int	builtin_envp(t_minishell *ms_data, t_minishell *shell_h, int fd)
{
	if (ms_data->builtin_cmd[1])
	{
		ft_putstr_fd("env: '", 2);
		ft_putstr_fd(ms_data->builtin_cmd[1], 2);
		ft_putstr_fd("': No such file or directory\n", 2);
		// g_status = 127;
		return (0);
	}
	while (shell_h->next)
	{
		ft_putstr_fd(*shell_h->envp, fd);
		ft_putstr_fd("=", fd);
		ft_putstr_fd(shell_h->value, fd);
		ft_putstr_fd("\n", fd);
		shell_h = shell_h->next;
	}
	ft_putstr_fd(*shell_h->envp, fd);
	ft_putstr_fd("=", fd);
	ft_putstr_fd(shell_h->value, fd);
	ft_putstr_fd("\n", fd);
	// g_status = 0;
	return (0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	t_minishell	*ms_data;
// 	t_minishell	*shell_h;

// 	(void)argc;
// 	(void)argv;
// 	ms_data = malloc(sizeof(t_minishell));
// 	shell_h = malloc(sizeof(t_minishell));
// 	shell_h->envp = envp;
// 	ms_data->builtin_cmd = argv;
// 	builtin_envp(ms_data, shell_h, 1);
// 	return (0);
// }
