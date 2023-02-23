/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/22 21:04:30 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	main(int argc, char **argv, char **envp)
{
	t_minishell		*ms_data = NULL;
	char			*readed;
	t_token			*head = NULL;
	t_pipe_group	*head_pipe = NULL;
	char			**splited;

	(void) argv;
	// (void) envp;
	if (argc != 1)
	{
		printf("wrong amount of arguments");
		return(0);
	}
	// 	error_args();
	ms_data = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
	if (!ms_data)
		return (1);
	while (1)
	{
		readed = readline("welcome to minishel: ");
		splited = ft_split_minishell(readed);
		add_history(readed);
		if(init_all(&head, ms_data, readed, splited, envp) == 0)
			return(0);
		// put_type_tok(&head);
		set_pipe_group(&head_pipe, &head);
		// printf("pipes: %i\n", count_pipes(&head));
		// printf("type: %i\n", ms_data->count_pipes);
		
	}
	free_token(&head);
	return (0);
}
