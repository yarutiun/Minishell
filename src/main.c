/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2023/03/20 21:50:10 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	(void)  envp;
	// int qwer;
	char	*readed;

	t_token	*head = NULL;
	char	**splited;
	// while (1)
	// {
		readed = "\"\'\"\'dljskfnkjlsdn kdfnslfndsjkln\'";
		splited = ft_split_minishell(readed);
		int i = 0;
		while(splited[i]){
			printf("%s\n", splited[i]);
			i++;
		}
		add_history(readed);
		init_list(&head, readed, splited);
		// put_type_tok(&head);
		printf("info = %s  %d  len = %i\n", head->next->info, head->type, head->len);
		// printf("%s   %i\n", head->next->info, head->next->type);
		// printf("%s   %i\n", head->next->next->info, head->next->next->type);
	// }
	return (0);
}