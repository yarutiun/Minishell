/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:27:46 by dsas              #+#    #+#             */
/*   Updated: 2023/04/03 10:34:26 by yarutiun         ###   ########.fr       */
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
	g_shell_h->envp[index] = ft_strdup(arg);
}

int	find_index_of_char(char *arg, char c)
{
	int	i;

	i = 0;
	while (arg[i] != c)
		i++;
	return (i);
}

void	set_new(char *arg)
{
	char	*st;
	int		j;

	st = ft_substr(arg, 0, find_index_of_char(arg, '=') + 1);
	j = find_path_env(g_shell_h->envp, st);
	if (j != -1)
	{
		free(g_shell_h->envp[j]);
		g_shell_h->envp[j] = arg;
	}
	else
		g_shell_h->envp[(g_shell_h->current_env)++] = arg;
	free(st);
}

void	print_export(void)
{
	int		i;

	i = 0;
	while (g_shell_h->envp[i])
	{
		if (!g_shell_h->envp[i])
			continue ;
		ft_putstr_fd("declare -x ", 2);
		ft_putstr_fd(g_shell_h->envp[i], 2);
		ft_putstr_fd("\n", 2);
		i++;
	}
}
