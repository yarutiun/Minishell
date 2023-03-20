/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:26:03 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/06 21:04:29 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

/* This function searches for an environment variable string str in the array
** of environment variables global->envp and returns the value of that variable.
** It does so by iterating through the array and using ft_strncmp to compare the
** variable names until it finds a match. It then returns a substring of the
** environment variable string starting from the end of the variable name
** (excluding the variable name itself) and continuing until the end of the
** string. If the variable is not found, it returns NULL. */
char	*get_path(char *str, t_global *global)
{
	int	i;

	i = 0;
	while (global->envp[i])
	{
		if (!ft_strncmp(global->envp[i], str, ft_strlen(str)))
			return (ft_substr(global->envp[i], ft_strlen(str),
					ft_strlen(global->envp[i]) - ft_strlen(str)));
		i++;
	}
	return (NULL);
}

/* This function takes a string argument str and a pointer to a
** t_global struct. It searches for an environment variable that matches the
** first characters of str, retrieves the path from that variable, and changes
** the current working directory to the retrieved path. If the path does not 
** exist, it prints an error message and returns a non-zero exit code. */
int	get_special_path(t_global *global, char *str)
{
	char	*buff;
	int		out;

	buff = get_path(str, global);
	out = chdir(buff);
	free(buff);
	if (out != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putendl_fd(" not exist", STDERR_FILENO);
	}
	return (out);
}

/* This function updates the current working directory (pwd) and the previous
** working directory (old_pwd) by assigning the value of pwd to old_pwd, and
** then updating the value of pwd to the current working directory using the
** getcwd() function. It also frees the old value of old_pwd and pwd. */
void	new_path(t_global *global)
{
	char	*buff;

	buff = ft_strdup(global->pwd);
	free(global->old_pwd);
	global->old_pwd = buff;
	free(global->pwd);
	global->pwd = getcwd(NULL, sizeof(NULL));
}
