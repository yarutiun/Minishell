/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:52:37 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/16 22:01:11 by hboichuk         ###   ########.fr       */
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

//function for starting
int	run_minishell(t_minishell *global_data)
{
	char	*readed;
	t_token	*head;
	char	**splited;
	
	readed = readline("<Hello   ");
	splited = ft_split_minishell(readed);
	//lexer part, we need some separate function for this
	init_list(&head, readed, splited);
	put_type_tok(&head);
	//quotes part?where is it?
	// need separate function for envp, tested it later
	init_envp_new_list(global_data);
	print_envp_new_list(global_data);// need separate function
	//function for history
	// parser part
	start_parser(global_data);
	//preparation for execution
	//reset function?
	return (1);
}

int	init_global_data(t_minishell	*ms_data, char **envp)
{
	// ms_data->argc = argc;we don't need it?
	// ms_data->argv = argv;here init?
	ms_data->envp = init_envp(envp);//firstly, we have to allocate mem for 2d-envp, later?
	if (!envp)
		return (1);
	ms_data->error = 0;//do we need it?
	ms_data->heredoc = false;
	ms_data->pid = NULL;
	ms_data->reset = false;
	//init for signals?
	return (1);
}

//should we separate all errors with numbers in error_handler.c?
int	main(int argc, char **argv, char **envp)
{
	t_minishell	*ms_data;//global data

	if (argc != 1 && argv)
		error_args();
	ms_data = (t_minishell *)ft_calloc(1, sizeof(t_minishell));
	if (!ms_data)
	{
		printf("Error with allocation memory");
		exit(1);
	}
	init_global_data(&ms_data, envp);
	while (1)
	{
		printf("Minishell is running");//just for check, can delete later or rewrite
		if(run_minishell(ms_data) == -1)
			break;
		else if (run_minishell(ms_data) == 1)
			continue;
	}
	//do we need pwd functions here or in init?
	//function for cleaning?
	return (0);
}
