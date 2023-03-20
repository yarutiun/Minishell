/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:06:59 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/04 15:24:42 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/built.h"

/* The pwd built-in in a shell returns the current working directory of the
** process. In other words, it shows the name of the directory where the user
** is currently located within the file system. When the pwd command is
** executed, the shell will print the full path of the current directory to
** the standard output. */
int	ft_pwd(t_global *global, t_simple_cmds *simple_cmd)
{
	(void) simple_cmd;
	ft_putendl_fd(global->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
