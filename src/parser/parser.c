/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:11:19 by hboichuk          #+#    #+#             */
/*   Updated: 2023/02/27 19:49:53 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	parser(t_global *global_struct)
{
	// t_simple_cmds	*one_cmd;

	global_struct->simple_cmds = NULL;
	count_pipes(global_struct);
	return(0);
}