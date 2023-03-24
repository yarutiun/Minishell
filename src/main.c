/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/24 13:43:08 by dsas             ###   ########.fr       */
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
	// (void)  envp;
	// int qwer;
	char	*readed;

	t_token	*head = NULL;
	t_pipe_group *pipes = NULL;
	char	**splited;
	// while (1)
	// {
		// readed = "\"\'\"\'dljskfnkjlsdn kdfnslfndsjkln\' owjeofijweijof woefjowijfe";
		// readed = readline(">prompt: ");

		readed = "echo d>fdg sdjf gkjfdhg >> df";

		// readed = readline("prompt > ");
		splited = ft_split_minishell(readed);
		assign_env(envp, &shell_h);
		add_history(readed);
		init_list(&head, readed, splited);
		put_type_tok(&head);
		// while(head)
		// {
		// 	printf("content: %s type: %i\n", head->info, head->type);
		// 	head = head->next;
		// }
		split_words(&head);
		// while(head)
		// {
		// 	printf("content: %s type: %i\n", head->info, head->type);
		// 	head = head->next;
		// }
		expander(&head);
		pipes = redirection(&head);
		count_last(pipes);
		// b_echo(pipes->argv);
		executor(pipes);
		free_t_token(&head);
		free_t_pipe(&pipes);
		free_shell_h();
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
	// }
	return (0);
}


		// int i = 0;
		// while(splited[i])
		//{
		// 	printf("%s\n", splited[i]);
		// 	i++;
		// }


// int main(int argc, char **argv, char **envp)
// {
//     (void) argc;
//     (void) argv;
//     assign_env(envp, &shell_h);
//     // printf("%s", shell_h->envp[1]);
//     // expand_and_print();
//     return(0);
// }
