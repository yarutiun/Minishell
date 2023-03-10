/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:24:30 by hboichuk          #+#    #+#             */
/*   Updated: 2023/02/23 16:32:36 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**init_envp(char **envp)
{
	char	**new_envp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (envp[i] != NULL)
		i++;
	new_envp = ft_calloc(sizeof(char *), i + 1);
	if (!new_envp)
		return (NULL);
	i = 0;
	while (envp[i] != NULL)
	{
		new_envp[i] = ft_strdup(envp[i]);
		if (new_envp[i] == NULL)
		{
			while (new_envp[j])
			{
				free(new_envp[j]);
				j++;
			}
			free(new_envp);
			return (new_envp);
		}
		i++;
	}
	return (new_envp);
}
