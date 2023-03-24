/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:56:50 by dsas              #+#    #+#             */
/*   Updated: 2023/03/24 14:13:27 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	throw_error(char *error)
{
	ft_putstr_fd(error, 2);
	free_t_pipe(shell_h->pipes);
	free_t_token(shell_h->head);
}

void	throw_error_exec(char *error)
{
	ft_putstr_fd(error, 2);
}
