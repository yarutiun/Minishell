/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:43:35 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/04 15:22:30 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/built.h"

/* The echo built-in in a shell, including Minishell, is used to print a 
** message to the standard output.*/
int	ft_echo(t_global *global, t_simple_cmds *simple_cmd)
{
	int		i;
	int		o;
	bool	lever;

	i = 1;
	lever = false;
	(void) global;
	while (simple_cmd->str[i] && simple_cmd->str[i][0] == '-'
			&& simple_cmd->str[i][1] == 'n')
	{
		o = 1;
		while (simple_cmd->str[1][o] == 'n')
			o++;
		if (simple_cmd->str[i][o] == '\0')
			lever = true;
		else
			break ;
		i++;
	}
	lines_print(i, simple_cmd->str, STDOUT_FILENO);
	if (lever == false)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
