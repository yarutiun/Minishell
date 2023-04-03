/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:25:52 by yarutiun          #+#    #+#             */
/*   Updated: 2023/04/03 10:34:41 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	find_path_env(char **env, char *key)
{
	int	i;

	i = 0;
	while (i < 1000)
	{
		if (env[i] && ft_strnstr(env[i], key, ft_strlen(key)))
			return (i);
		i++;
	}
	return (-1);
}

char	*cut_key(char **env, int index, char *key)
{
	char	*buf;

	buf = ft_substr(env[index], ft_strlen(key) + 1,
			(ft_strlen(env[index]) - 1 - ft_strlen(key)));
	return (buf);
}

char	*get_working_path_loop(char ***binary_paths, char **one_path,
								char **one_command_path, char	*cmd)
{
	int	i;

	i = -1;
	while ((*binary_paths)[++i])
	{
		*one_path = ft_strjoin((*binary_paths)[i], "/");
		*one_command_path = ft_strjoin(*one_path, cmd);
		free(*one_path);
		if (!access(*one_command_path, F_OK))
		{
			ft_free_strings(*binary_paths);
			return (*one_command_path);
		}
		free(*one_command_path);
	}
	ft_free_strings(*binary_paths);
	return (NULL);
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
	if (j == -1)
		return (NULL);
	one_command_path = ft_strjoin(env[j], cmd);
	if (!access(one_command_path, F_OK))
		return (one_command_path);
	free(one_command_path);
	i = find_path_env(env, "PATH=");
	if (i == -1)
		return (NULL);
	binary_paths = ft_split(env[i] + 5, ':');
	return (get_working_path_loop(&binary_paths,
			&one_path, &one_command_path, cmd));
}
