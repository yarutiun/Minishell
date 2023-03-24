/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/24 18:06:04 by yarutiun         ###   ########.fr       */
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


// int	main(int argc, char **argv, char **envp)
// {
// 	(void) argc;
// 	(void) argv;
// 	char	*readed;


// 	char	**splited;
// 	assign_env(envp, &shell_h);
// 	signals();

// 		readed = "pwd >rot|ls";
// 		splited = ft_split_minishell(readed);
// 		add_history(readed);
// 		init_list(&(shell_h->head), readed, splited);
// 		t_token *check = shell_h->head;
// 		t_pipe_group *pipe_check = shell_h->pipes;
// 		put_type_tok(&(shell_h->head));
// 		split_words(&(shell_h->head));
// 		expander(&(shell_h->head));
// 		shell_h->pipes = redirection(&(shell_h->head));
// 		if(shell_h->pipes == NULL)
// 			return 1;
// 		count_last(shell_h->pipes);
// 		executor(shell_h->pipes);
// 		free_t_token(&(shell_h->head));
// 		free_t_pipe(&(shell_h->pipes));
// 		free_shell_h();
// 		return (0);
// }



int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	// (void)  envp;
	// int qwer;
	char	*readed;


	char	**splited;
	assign_env(envp, &shell_h);
	signals();
	while (1)
	{
		// readed = "\"\'\"\'dljskfnkjlsdn kdfnslfndsjkln\' owjeofijweijof woefjowijfe";
		// readed = readline(">prompt: ");

		// readed = "cat TODO";
		readed = readline("minishell > ");
		if(!readed)
			exit(EXIT_SUCCESS);
		splited = ft_split_minishell(readed);
		add_history(readed);
		init_list(&(shell_h->head), readed, splited);
		t_token *check = shell_h->head;
		put_type_tok(&(shell_h->head));
		// while(head)
		// {
		// 	printf("content: %s type: %i\n", head->info, head->type);
		// 	head = head->next;
		// }
		split_words(&(shell_h->head));
		// while(head)
		// {
		// 	printf("content: %s type: %i\n", head->info, head->type);
		// 	head = head->next;
		// }
		expander(&(shell_h->head));
		shell_h->pipes = redirection(&(shell_h->head));
		if(shell_h->pipes == NULL)
			continue;
		count_last(shell_h->pipes);
		// b_echo(pipes->argv);
		executor(shell_h->pipes);
		// c
		// ft_env();
		// printf("info = %s  %d  len = %i\n", head->next->info, head->type, head->len);
		// printf("%s   %i\n", head->next->info, head->next->type);
		// while(pipes)
		// {
		// 	printf("cmd: %s\n", pipes->cmd);
		// 	int i = 0;
		// 	while(pipes->argv[i])
		// 	{
		// 		printf("	pipe group:	%s\n", pipes->argv[i]);
		// 		i++;
		// 	}
		// 	pipes = pipes->next;
		// }
		// ft_pwd();
		// printf("%s%i\n", head->next->next->info, head->next->next->type);
		free_t_token(&(shell_h->head));
		free_t_pipe(&(shell_h->pipes));
	}
	free_shell_h();
	return (0);
}


// 		// int i = 0;
// 		// while(splited[i])
// 		//{
// 		// 	printf("%s\n", splited[i]);
// 		// 	i++;
// 		// }


// // int main(int argc, char **argv, char **envp)
// // {
// //     (void) argc;
// //     (void) argv;
// //     assign_env(envp, &shell_h);
// //     // printf("%s", shell_h->envp[1]);
// //     // expand_and_print();
// //     return(0);
// // }
