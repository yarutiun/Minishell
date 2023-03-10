/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hboichuk <hboichuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:56:10 by hboichuk          #+#    #+#             */
/*   Updated: 2023/02/27 17:50:48 by hboichuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	count_pipes(t_global *global_struct)
{
	t_token	*tmp;

	tmp = global_struct->lexer_list;
	global_struct->pipes = 0;
	while (tmp)
	{
		if (tmp->tok_type == PIPE)
			global_struct->pipes++;
		tmp = tmp->next;
	}
	// printf("%d", global_struct->pipes);
}