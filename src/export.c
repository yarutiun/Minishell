/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:27:46 by dsas              #+#    #+#             */
/*   Updated: 2023/03/24 11:55:33 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	check_keyword(char *args)
{
	int			i;
	short int	index;

	i = 0;
	index = 0;
	if (!args || !args[0] || args[0] == '=')
		return (1);
	if (args[ft_strlen(args) - 1] != '=')
		return (1);
	while (args[i] && args[i] != '=')
	{
		if (ft_isalpha(args[i]))
			index = 1;
		else
			if (ft_isdigit(args[i]) && !index)
				return (1);
		else if (args[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	change_env(char *arg, int index)
{
	shell_h->envp[index] = ft_strdup(arg);
}

int	find_index_of_char(char *arg, char c)
{
	int	i = 0;

	while(arg[i] != c)
		i++;
	return (i);
}

void	set_new(char *arg)
{
	char	*st;
	int		j;

	st = ft_substr(arg, 0, find_index_of_char(arg, '=') + 1);
	j = find_path_env(shell_h->envp, st);
	if (j != -1)
	{
		free(shell_h->envp[j]);
		shell_h->envp[j] = arg;
	}
	else
		shell_h->envp[(shell_h->current_env)++] = arg;
	// free(st);
}

// void	add_env(char *arg)
// {
// 	int		indx;
// 	char	*sub;

// 	indx = find_index_of_char(arg, '=');
// 	if (indx == -1)
// 		indx = ft_strlen(arg);
// 	sub = ft_substr(arg, 0, indx);
// 	indx = find_keyword(sub);
// 	free(sub);
// 	if (indx == -1)
// 		set_new(arg);
// 	else
// 		change_env(arg, indx);
// }

void	print_export(void)
{
	int		i;

	i = 0;
	while (shell_h->envp[i])
	{
		if (!shell_h->envp[i])
			continue;
		ft_putstr_fd("declare -x ", 2);
		ft_putstr_fd(shell_h->envp[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
}

int	b_export(char **args)
{
	int	i;

	if (!args[1])
	{
		print_export();
		return (1);
	}
	i = 0;
	if (check_keyword(args[1]) || !args[2])
	{
		ft_putstr_fd("minishell: export: `", 2);
		ft_putstr_fd(args[i], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	set_new(ft_strjoin(args[1], args[2]));
	return (0);
}
