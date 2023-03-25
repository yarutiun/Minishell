/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/25 17:05:33 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

t_minishell *shell_h = NULL;

void	count_last(t_pipe_group *pipes)
{
	shell_h->last = -1;
	while(pipes)
	{
		pipes = pipes->next;
		shell_h->last++;
	}
}


int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	char	*readed;


	char	**splited;

	assign_env(envp);
	put_lvl();
	signals();

		readed = "pwd >> txt | pwd | grep a";
		splited = ft_split_minishell(readed);
		add_history(readed);
		if((init_list(&(shell_h->head), readed, splited) == 1))
			return 0;
		t_token *check = shell_h->head;
		t_pipe_group *pipe_check = shell_h->pipes;
		put_type_tok(&(shell_h->head));
		split_words(&(shell_h->head));
		expander(&(shell_h->head));
		shell_h->pipes = redirection(&(shell_h->head));
		if(shell_h->pipes == NULL)
			return 1;
		count_last(shell_h->pipes);
		executor(shell_h->pipes);
		free_t_token(&(shell_h->head));
		free_t_pipe(&(shell_h->pipes));
		free_shell_h();
		return (0);
}
