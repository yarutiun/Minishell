/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:34:01 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/06 20:08:50 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/built.h"

/* This function iterates through the arr parameter until it reaches the end
** of the array, and for each element, it allocates memory for a new string in
** out and copies the string from the corresponding element of arr to the new
** element of out. If it reaches the last element of arr, it also adds the str
** parameter to out before copying the last element of arr. If there is any
** memory allocation error during the process, it frees the out array and
** returns a NULL pointer. Finally, it returns the "out" array. */
char	**add_variable_loop(char **arr, char **out, char *str)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (arr[i + 1] == NULL)
		{
			out[i] = ft_strdup(str);
			out[i + 1] = ft_strdup(arr[i]);
		}
		else
			out[i] = ft_strdup(arr[i]);
		if (out[i] == NULL)
		{
			free_arr(out);
			return (out);
		}
		i++;
	}
	return (out);
}

/* This function takes an array of strings arr and a new string str, and adds
** str to the end of the array. It first removes any enclosing quotes from str
** using the deleting_quotes function. Then it allocates memory for a new array
** out that is one element larger than arr. It copies all the strings from arr
** to out, and then adds str to the end of out. Finally, it returns out. */
char	**add_variable(char **arr, char *str)
{
	size_t	i;
	char	**out;

	i = 0;
	if (str[if_equal_sign(str)] == '\"')
		deleting_quotes(str, '\"');
	if (str[if_equal_sign(str)] == '\'')
		deleting_quotes(str, '\'');
	while (arr[i] != NULL)
		i++;
	out = ft_calloc(sizeof(char *), i + 2);
	if (!out)
		return (NULL);
	i = 0;
	add_variable_loop(arr, out, str);
	return (out);
}

/* This is an implemintation of "export" command in bash.
** The function takes in a t_global and t_simple_cmds structure as input.
** It checks if there are any arguments passed to the export command, and if
** not, it prints the current environment variables using the ft_env function.
** If there are arguments, the function checks if they are valid environment
** variable names using the check_input_parameter function.
** If they are valid, it checks if the variable already exists and updates it,
** or creates a new one. */
int	ft_export(t_global *global, t_simple_cmds *simple_cmd)
{
	char	**buf;
	int		i;

	i = 1;
	if (!simple_cmd->str[1] || simple_cmd->str[1][0] == '\0')
		ft_env(global, simple_cmd);
	else
	{
		while (simple_cmd->str[i])
		{
			if (check_input_parameter(simple_cmd->str[i]) == 0
				&& check_variable(global, simple_cmd->str[i]) == 0)
			{
				if (simple_cmd->str[i])
				{
					buf = add_variable(global->envp, simple_cmd->str[i]);
					free_arr(global->envp);
					global->envp = buf;
				}
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
