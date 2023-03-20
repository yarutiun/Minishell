/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:05:20 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/06 20:16:53 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

/* Searching equal sign in command string */
size_t	if_equal_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i + 1);
		i++;
	}
	return (0);
}

/* This function prints a set of strings separated by spaces and a newline
** character at the end. */
void	lines_print(int i, char **str, int out)
{
	while (str[i])
	{
		ft_putstr_fd(str[i++], out);
		if (str[i])
			ft_putchar_fd(' ', out);
	}
}

/* This function takes a pointer to a global structure and a string as input.
** It first checks if the character after the equal sign in the input string
** is either a single or double quote, and if so, removes them using the
** deleting_quotes() function. Then, it iterates through the envp array in
** the global structure and checks if the input string matches any of the
** environment variables. If a match is found, it replaces the old
** environment variable with the new one in the envp array and returns 1.
** If no match is found, it returns 0. */
int	check_variable(t_global *global, char *str)
{
	int	i;

	i = 0;
	if (str[if_equal_sign(str)] == '\"')
		deleting_quotes(str, '\"');
	if (str[if_equal_sign(str)] == '\'')
		deleting_quotes(str, '\'');
	while (global->envp[i])
	{
		if (ft_strncmp(global->envp[i], str,
				if_equal_sign(global->envp[i])) == 0)
		{
			free(global->envp[i]);
			global->envp[i] = ft_strdup(str);
			return (1);
		}
		i++;
	}
	return (0);
}

/* The function check_identifier takes in a character c and returns 1
** if the character is a valid identifier in the context of a shell command,
** and 0 otherwise. The function considers characters that can be used in
** variable names, special characters, and whitespace characters as
** valid identifiers. */
int	check_identifier(char c)
{
	return (c == '|' || c == '<' || c == '>' || c == '[' || c == ']'
		|| c == '\'' || c == '\"' || c == ' ' || c == ',' || c == '.'
		|| c == ':' || c == '/' || c == '{' || c == '}' || c == '+'
		|| c == '^' || c == '%' || c == '#' || c == '@' || c == '!'
		|| c == '~'
		|| c == '=' || c == '-' || c == '?' || c == '&' || c == '*');
}

/* This function checks if a given input parameter (in the form of a string)
** is a valid identifier for use in environment variables. It first
** checks that the parameter does not start with a digit and that it has
** an equal sign somewhere in it (which separates the name from the value).
** It then checks that each character before the equal sign is a valid
** identifier character, according to the check_identifier function.
** If any of these checks fail, it returns "EXIT_FAILURE", otherwise,
** it returns "EXIT_SUCCESS". */
int	check_input_parameter(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (error_export(str));
	if (if_equal_sign(str) == 0)
		return (EXIT_FAILURE);
	if (str[0] == '=')
		return (error_export(str));
	while (str[i] != '=')
	{
		if (check_identifier(str[i]))
			return (error_export(str));
		i++;
	}
	return (EXIT_SUCCESS);
}
