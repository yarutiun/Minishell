/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:42:54 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/17 12:33:51 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

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