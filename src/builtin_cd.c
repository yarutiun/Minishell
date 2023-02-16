/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:57:16 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/13 19:24:19 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

//check if there are arguments
//if there are, call to chdir
//check if there is an error

int	builtin_cd(t_minishell *ms_data)
{
	int		i;
	char	*home;
	
	i = 0;
	if (ms_data->argv[1] == NULL)
	{
		while (ms_data->envp[i] != NULL)
		{
			if (ft_strncmp(ms_data->envp[i], "HOME=", 5) == 0)
				break ;
			i++;
		}
		home = ft_substr(ms_data->envp[i], 5, ft_strlen(ms_data->envp[i]));
		chdir(home);
	}
	else if (chdir(ms_data->argv[1]) == -1)
	{
		printf("minishell: cd: %s: No such file or directory\n", ms_data->argv[1]);
		return (1);
	}
	return (0);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	t_minishell	*ms_data;

// 	ms_data = malloc(sizeof(t_minishell));
// 	ms_data->argv = malloc(sizeof(char *));
// 	ms_data->argv[1] = malloc(sizeof(char) * 100);
// 	ft_strcpy(ms_data->argv[1], "/Users/nrenz/42/minishell");
// 	printf("here\n");
// 	builtin_cd(ms_data);
// 	printf("line 52\n");
// 	return (0);
// }

// #Programm echo

// #1. check if the first argument is echo
// #2. check if the second argument is NULL or empty
// #3. if it is NULL or empty, we need to print a newline
// #4. if it is not NULL or empty, we need to print the second argument
// #5. if there are more arguments, we need to print a space between the arguments

// #Programm env

// #1. check if the first argument is env
// #2. if it is env, we need to print the environment
// #3. if there are more arguments, we need to print an error message

// #Programm exit

// #1. check if the first argument is exit
// #2. if it is exit, we need to exit the programm

// #Programm export

// #1. check if the first argument is export
// #2. check if the second argument is NULL or empty
// #3. if it is NULL or empty, we need to print an error message
// #4. if it is not NULL or empty, we need to check if the second argument is a valid environment variable
// #5. if it is a valid environment variable, we need to add it to the environment
// #6. if it is not a valid environment variable, we need to print an error message

// #Programm pwd

// #1. check if the first argument is pwd
// #2. if it is pwd, we need to print the current working directory
// #3. if there are more arguments, we need to print an error message

// #Programm unset

// #1. check if the first argument is unset
// #2. check if the second argument is NULL or empty
// #3. if it is NULL or empty, we need to print an error message
// #4. if it is not NULL or empty, we need to check if the second#1. check if the first argument is cd
// #2. check if the second argument is NULL or empty
// #3. if it is NULL or empty, we need to change the directory to the HOME directory
// #4. if it is not NULL or empty, we need to check if the second argument is a valid directory
// #5. if it is a valid directory, we need to change the directory to the second argument
// #6. if it is not a valid directory, we need to print an error message
