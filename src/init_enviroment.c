/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enviroment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:16:26 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/16 15:32:04 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft/libft.h"
#include "../inc/include.h"

t_minishell	*new_envp(t_minishell *ms_data)
{
	t_minishell	*new;

	new = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
	if (!new)
		return (NULL);
	new->key = ft_strdup(ms_data->key);
	new->value = ft_strdup(ms_data->value);
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
