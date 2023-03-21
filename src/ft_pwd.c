/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:06:59 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/21 15:09:24 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../inc/include.h"

// /* The pwd built-in in a shell returns the current working directory of the
// ** process. In other words, it shows the name of the directory where the user
// ** is currently located within the file system. When the pwd command is
// ** executed, the shell will print the full path of the current directory to
// ** the standard output. */
// char	*ft_pwd(t_minishell *global)
// {
// 	int i;
// 	int j;
// 	char *pwd;

// 	i = 0;
// 	j = 0;
// 	while(global->envp[i])
// 	{
// 	printf("ABC\n");	
// 		if(global->envp[i][0] == 'P' && global->envp[i][1] == 'W' && global->envp[i][2] == 'D')
// 		{
// 			pwd = ft_strdup(global->envp[i]);
// 			return(pwd);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// // int main(int argc, char **argv, char **envp)
// // {
// // 	(void) argc;
// // 	(void) argv;
// // 	char *pwd;
// // 	t_minishell *global = 0;
// // 	global = malloc(sizeof(t_minishell));
// // 	assign_env(envp, global);
// // 	// printf("%s", global->envp[1]);
// // 	pwd = ft_pwd(global);
// // 	return(0);
// // }