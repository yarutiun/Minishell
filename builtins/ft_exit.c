/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:28:09 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/22 09:19:40 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/built.h"

/* Define an exit code at exit of minishell. We can keep only numeric
** values of codes */
// void	define_exit_code(char **str)
// {
// 	int	exit_code;

// 	if (!str[1])
// 		exit_code = 0;
// 	else if (ft_strdigit(str[1]))
// 		exit_code = ft_atoi(str[1]);
// 	else
// 	{
// 		ft_putstr_fd("HD_minishell: exit: ", 2);
// 		ft_putstr_fd(str[1], 2);
// 		ft_putstr_fd(": numeric argument required! \n", 2);
// 		exit_code = 255;
// 	}
// 	free_arr(str);
// 	exit(exit_code);
// }

// /* The exit built-in in the Minishell project is responsible for exiting the
// ** shell program. It is used when the user types the exit command in the
// ** terminal. */
// int	ft_exit(t_global *global, t_simple_cmds *simple_cmd)
// {
// 	char	**str;

// 	ft_putstr_fd("EXIT", 2);
// 	if (simple_cmd->str[1] && simple_cmd->str[2])
// 	{
// 		ft_putstr_fd("HD_minishell: exit: too many arguments! \n", 2);
// 		return (EXIT_FAILURE);
// 	}
// 	str = ft_arrdup(simple_cmd->str);
// 	define_exit_code(str);
// 	return (0);
// }
