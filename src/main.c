/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/16 17:03:31 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

extern int	g_status;

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*ms_data;
	char	*readed;
	t_token	*head;
	char	**splited;

	// if (argc != 1)
	// 	error_args();
	ms_data = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
	if (!ms_data)
		return (1);
	ms_data->argc = argc;
	ms_data->argv = argv;
	ms_data->envp = envp;
	if (!envp)
		return (1);
	ms_data->error = 0;
	while (1)
	{
		readed = readline("<qwert   ");
		splited = ft_split_minishell(readed);
		init_list(&head, readed, splited);
		put_type_tok(&head);
		printf("%s	%i\n", head->info, head->type);
		init_envp_new_list(ms_data);
		print_envp_new_list(ms_data);
	}
	return (0);
}
