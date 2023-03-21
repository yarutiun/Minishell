/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:25:52 by yarutiun          #+#    #+#             */
/*   Updated: 2023/03/21 20:12:27 by yarutiun         ###   ########.fr       */
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

// char	*get_working_path(char *cmd, char **env)
// {
// 	int		i;
// 	char	**binary_paths;
// 	char	*one_path;
// 	char	*one_command_path;

// 	i = find_path_env(env);
// 	binary_paths = ft_split(env[i] + 5, ':');
// 	i = -1;
// 	while (binary_paths[++i])
// 	{
// 		one_path = ft_strjoin(binary_paths[i], "/");
// 		one_command_path = ft_strjoin(one_path, cmd);
// 		free(one_path);
// 		if (!access(one_command_path, F_OK))
// 		{
// 			ft_free_strings(binary_paths);
// 			return (one_command_path);
// 		}
// 		free(one_command_path);
// 	}
// 	ft_free_strings(binary_paths);
// 	return (NULL);
// }

// int main (int argc, char **argv, char **envp)
// {
//     int i = 0;
//     char *buf;
//     i = find_path_env(envp, "PATH");
//     buf = cut_key(envp, i, "PATH");
//     printf("%s", buf);
//     return(0);
// }