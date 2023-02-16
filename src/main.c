/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/16 16:14:15 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

// void sig_handler(int signal)
// {
//     if(signal == SIGINT)
//     {
//         printf("\nexiting shell");

//         // rl_replace_line();
//         // readline("<qwert   ");
//     }
// }

// char	*ft_strcat(char *s1, const char *s2)
// {
// 	int		index;
// 	size_t	i;

// 	index = strlen(s1);
// 	i = 0;
// 	while (i < strlen((char *)s2))
// 	{
// 		s1[index] = s2[i];
// 		i++;
// 		index++;
// 	}
// 	s1[index] = '\0';
// 	return (s1);
// }

// void	prompt(void)
// {
// 	char	cwd[256];

// 	getcwd(cwd, sizeof(cwd));
// 	ft_strcat(cwd, " : ");
// 	ft_putstr_fd(cwd, 1);
// }

// void	sig_handle(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		ft_putstr_fd("\n", 1);
// 		prompt();
// 	}
// }

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
