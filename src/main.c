/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/20 16:39:12 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*ms_data;
	char	*readed;
	t_token	*head;
	char	**splited;

	(void) argv;
	(void) envp;
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
		put_type_tok(&head);
		printf("type: %i\n", head->type);
	}
	return (0);
}

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
