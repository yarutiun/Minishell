/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/22 09:27:03 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

t_minishell *shell_h = NULL;

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	// (void)  envp;
	// int qwer;
	char	*readed;

	t_token	*head = NULL;
	char	**splited;
	// while (1)
	// {
		// readed = "\"\'\"\'dljskfnkjlsdn kdfnslfndsjkln\' owjeofijweijof woefjowijfe";
		// readed = readline(">prompt: ");
		readed = "dsfdsf $HOME $$$$$$$$$$ eisadk";
		splited = ft_split_minishell(readed);
		assign_env(envp, &shell_h);
		add_history(readed);
		init_list(&head, readed, splited);
		put_type_tok(&head);
		expander(&head);
		// ft_env();
		// printf("info = %s  %d  len = %i\n", head->next->info, head->type, head->len);
		// printf("%s   %i\n", head->next->info, head->next->type);
		while(head)
		{
			printf("content: %s type: %i\n", head->info, head->type);
			head = head->next;
		}
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