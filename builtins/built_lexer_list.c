/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_lexer_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:10:10 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/06 21:26:50 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/built.h"

/* This is a function that returns a pointer to a function that is a built-in
** command in a shell program. The function takes a string str as input, which
** is the name of the command to be executed, and returns a pointer to the
** corresponding built-in function. The function built_arr searches for the
** name of the command in an array of strings that contains the names of all
** the built-in commands, and if the name matches, it returns a pointer to
** the corresponding function. If the name is not found in the array, the
** function returns NULL. */
int	(*built_arr(char *str))(t_global *global, t_simple_cmds *simple_cmd)
{
	static void	*builtins[7][2] = {
	{"echo", ft_echo},
	{"pwd", ft_pwd},
	{"cd", ft_cd},
	{"export", ft_export},
	{"exit", ft_exit},
	{"unset", ft_unset},
	{"env", ft_env},
	};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(builtins[i][0], str, ft_strlen(builtins[i][0])))
				return (builtins[i][1]);
		}
		i++;
	}
	return (NULL);
}

/* Конструкция 
int (*built_arr(char *str))(t_global *global, t_simple_cmds *simple_cmd) 
это объявлениефункции built_arr, которая принимает в качестве аргумента
указатель на строку char *str, и возвращает указатель на функцию, 
принимающую два аргумента типа t_global * и t_simple_cmds * и возвращает
целочисленное значение int.

В данном случае, built_arr возвращает указатель на одну из семи 
функций-встроенных команд (builtins), которые определены в статическом
массиве builtins. Функция built_arr ищет функцию в массиве по имени 
команды, которая передается в качестве аргумента str. Если
соответствующая функция найдена, то указатель на нее 
возвращается из built_arr.

Пример вызова функции, возвращаемой built_arr:

int (*builtin_func)(t_global *global, t_simple_cmds *simple_cmd);
builtin_func = built_arr("echo");
if (builtin_func != NULL)
    builtin_func(global, simple_cmd);
	
В этом примере, builtin_func становится указателем на функцию,
которая соответствует команде "echo". Если такая функция найдена, 
она вызывается с передачей двух аргументов global и simple_cmd.*/