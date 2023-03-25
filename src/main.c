/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/25 17:52:40 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

t_minishell *g_shell_h = NULL;

void	count_last(t_pipe_group *pipes)
{
	g_shell_h->last = -1;
	while (pipes)
	{
		pipes = pipes->next;
		g_shell_h->last++;
	}
}

void	init_main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	assign_env(envp);
	put_lvl();
	signals();
}

int	main(int argc, char **argv, char **envp)
{
	char	*readed;
	char	**splited;

	init_main(argc, argv, envp);
	while (1)
	{
		if(!(readed = readline("minishell > ")))
			return (0);			
		splited = ft_split_minishell(readed);
		add_history(readed);
		if ((init_list(&(g_shell_h->head), readed, splited) == 1))
			return (0);
		put_type_tok(&(g_shell_h->head));
		split_words(&(g_shell_h->head));
		expander(&(g_shell_h->head));
		g_shell_h->pipes = redirection(&(g_shell_h->head));
		if (g_shell_h->pipes == NULL)
			return (1);
		count_last(g_shell_h->pipes);
		executor(g_shell_h->pipes);
		free_t_token(&(g_shell_h->head));
		free_t_pipe(&(g_shell_h->pipes));
	}
	free_shell_h();
	return (0);
}
