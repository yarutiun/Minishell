/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:08:23 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/06 20:18:06 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/built.h"

/* This function takes in three arguments: an array of strings arr, an output 
** array of strings out, and a string str. It returns an array of strings that
** has all the elements of arr except for those that match str in the form
** VAR=VALUE.
** The function iterates through the elements of arr and checks if the current
** element is in the form VAR=VALUE and matches str. If it doesn't match,
** it is added to the out array using the ft_strdup function, which duplicates
** a string. If the ft_strdup function fails to allocate memory for the
** duplicated string, the function returns out.
**
** Once all the non-matching elements have been added to the out array,
** the function returns "out". */
char	**deleting_loop(char **arr, char **out, char *str)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (arr[i] != NULL)
	{
		if (!(ft_strncmp(arr[i], str, if_equal_sign(arr[i]) - 1) == 0
				&& str[if_equal_sign(arr[i])] == '\0'
				&& arr[i][ft_strlen(str)] == '='))
		{
			out[o] = ft_strdup(arr[i]);
			if (out[o] == NULL)
			{
				free_arr(out);
				return (out);
			}
			o++;
		}
		i++;
	}
	return (out);
}

/* This function takes in two arguments, a pointer to a string array
** arr and a pointer to a string str. It deletes the variable str
** from the environment by creating a new string array out without
** the variable str.*/
char	**var_deleting(char **arr, char *str)
{
	char	**out;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	out = ft_calloc(sizeof(char *), i + 1);
	if (!out)
		return (NULL);
	out = deleting_loop(arr, out, str);
	return (out);
}

/* unset is a built-in command in the minishell project that removes
** an environment variable from the shell's environment. When unset
** is called with one or more arguments, it will remove each
** specified environment variable from the shell's environment.
** If unset is called with no arguments, it will do nothing and
** return a success exit code.*/
int	ft_unset(t_global *global, t_simple_cmds *simple_cmd)
{
	char	**buff;

	if (error_unset(simple_cmd) == 1)
		return (EXIT_FAILURE);
	else
	{
		buff = var_deleting(global->envp, simple_cmd->str[1]);
		free_arr(global->envp);
		global->envp = buff;
	}
	return (EXIT_SUCCESS);
}
