/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:25:52 by yarutiun          #+#    #+#             */
/*   Updated: 2023/03/24 18:12:44 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	find_path_env(char **env, char *key)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], key, ft_strlen(key)))
			return(i);
		i++;
	}
	return (-1);
}

char *cut_key(char **env, int index, char *key)
{
    char *buf;

    buf = ft_substr(env[index], ft_strlen(key) + 1, (ft_strlen(env[index]) - 1 - ft_strlen(key)));
    return(buf);
}

char	*get_working_path(char *cmd, char **env)
{
	int		i;
	int		j;
	char	**binary_paths;
	char	*one_path;
	char	*one_command_path;

	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	j = find_path_env(env, "PWD=");
	one_command_path = ft_strjoin(env[j], cmd);
	if (!access(one_command_path, F_OK))
		return (one_command_path);
	free(one_command_path);
	i = find_path_env(env, "PATH=");
	binary_paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (binary_paths[++i])
	{
		one_path = ft_strjoin(binary_paths[i], "/");
		one_command_path = ft_strjoin(one_path, cmd);
		free(one_path);
		if (!access(one_command_path, F_OK))
		{
			ft_free_strings(binary_paths);
			return (one_command_path);
		}
		free(one_command_path);
	}
	ft_free_strings(binary_paths);
	return (NULL);
}
