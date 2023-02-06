/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrenz <nrenz@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:42:54 by nrenz             #+#    #+#             */
/*   Updated: 2023/02/06 15:43:51 by nrenz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

void	error_handler(char *error_msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("", 2);
}
