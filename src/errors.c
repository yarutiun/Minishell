/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:07:53 by yarutiun          #+#    #+#             */
/*   Updated: 2023/02/16 17:39:56 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

extern int	g_status;

void	error_handler(char *error_msg)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
    exit(EXIT_FAILURE);
}

void	*das_error(int err_type, char *param, int fd)
{
	g_status = fd;
	if (err_type == QUOTE)
		ft_putstr_fd("42minishell: error with matching quotes!\n", 2);
	else if (err_type == NDIR)
		ft_putstr_fd("42minishell: no such file or directory!\n", 2);
	else if (err_type == NPERM)
		ft_putstr_fd("42minishell: permission denied!\n", 2);
	else if (err_type == NCMD)
		ft_putstr_fd("42minishell: wrong command or command not found!\n", 2);
	else if (err_type == DUPERR)
		ft_putstr_fd("42minishell: duplication failed!\n", 2);
	else if (err_type == FORKERR)
		ft_putstr_fd("42minishell: fork creation failed!\n", 2);
	else if (err_type == PIPERR)
		ft_putstr_fd("42minishell: pipe creation failed!\n", 2);
	else if (err_type == PIPENDERR)
		ft_putstr_fd("42minishell: syntax error near unexpected token `|'!\n", 2);
	else if (err_type == MEM)
		ft_putstr_fd("42minishell: no memory left on PC or memory error!", 2);
	else if (err_type == IS_DIR)
		ft_putstr_fd("42minishell: this is a directory!\n", 2);
	else if (err_type == NOT_DIR)
		ft_putstr_fd("42minishell: this is not a directory!\n", 2);
	ft_putendl_fd(param, 2);
	return (NULL);
}
