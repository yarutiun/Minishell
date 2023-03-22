/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:06:59 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/22 09:27:45 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

// /* The pwd built-in in a shell returns the current working directory of the
// ** process. In other words, it shows the name of the directory where the user
// ** is currently located within the file system. When the pwd command is
// ** executed, the shell will print the full path of the current directory to
// ** the standard output. */
char	*ft_pwd(void)
{
	int i;
	int j;
	char *pwd;

	i = 0;
	j = 0;
	while(shell_h->envp[i])
	{
		if(shell_h->envp[i][0] == 'P' && shell_h->envp[i][1] == 'W' && shell_h->envp[i][2] == 'D')
		{
			pwd = ft_strdup(shell_h->envp[i]);
	        // printf("%s\n", pwd);
			return(pwd);
		}
		i++;
	}
	return (0);
}



// int main(int argc, char **argv, char **envp)
// {
// 	(void) argc;
// 	(void) argv;
// 	char *pwd;
// 	t_minishell *shell_h = 0;
// 	shell_h = malloc(sizeof(t_minishell));
// 	assign_env(envp, shell_h);
// 	printf("%s", shell_h->envp[1]);
// 	pwd = ft_pwd();
//     printf("%s", pwd);
// 	return(0);
// }

