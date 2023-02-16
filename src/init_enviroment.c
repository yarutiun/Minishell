/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enviroment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:16:26 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/16 21:18:29 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft/libft.h"
//for init envp? why new envp it's a struct?
#include "../inc/include.h"

t_minishell	*new_envp(t_minishell *ms_data)
{
	t_minishell	*new;

	new = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
	if (!new)
		return (NULL);
	// new->key = ft_strdup(ms_data->key);
	// new->value = ft_strdup(ms_data->value);
	new->next = NULL;
	return (new);
}

// t_minishell	*envp_new_list(t_minishell *ms_data)
// {
// 	t_minishell	*temp;
// 	t_minishell	*new;

// 	temp = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
// 	if (!temp || !new)
// 		return (NULL);
// 	else
// 	{
// 		temp = ms_data;
// 		while (temp->next)
// 			temp = temp->next;
// 		temp->next = new;
// 	}
// 	return (new);
// }

void	init_envp_new_list(t_minishell *ms_data)
{
	int			i;
	t_minishell	*new;

	i = 0;
	while (ms_data->envp[i])
	{
		ms_data->key = ft_substr(ms_data->envp[i], 0, \
						ft_strchr(ms_data->envp[i], '=') - ms_data->envp[i]);
		ms_data->value = ft_strdup(ft_strchr(ms_data->envp[i], '=') + 1);
		new = new_envp(ms_data);
		i++;
	}
}

void	print_envp_new_list(t_minishell *ms_data)
{
	while (ms_data->next)
	{
		printf("%s=%s\n", ms_data->key, ms_data->value);
		ms_data = ms_data->next;
	}
}

// int	main(int argc, char **argv, char **envp)
// {
// 	t_minishell	*ms_data;
// 	(void)argc;
// 	(void)argv;
// 	(void)envp;

// 	ms_data = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
// 	init_envp_list(ms_data);
// 	print_envp_new_list(ms_data);
// 	return (0);
// }

//my init
char	**init_envp(char **envp)
{
	char	**new_envp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (envp[i] != NULL)
		i++;
	new_envp = ft_calloc(sizeof(char *), i++);
	if(!new_envp)
		return (NULL);
	i = 0;
	while (envp[i])
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
