/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarutiun <yarutiun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:26:23 by ddzuba            #+#    #+#             */
/*   Updated: 2023/03/25 17:49:31 by yarutiun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/include.h"

int	ft_env(void)
{
	int	i;

	i = 0;
	while (i < g_shell_h->current_env)
	{
		if (g_shell_h->envp[i] == NULL)
		{
			i++;
			continue ;
		}
		printf("%s\n", g_shell_h->envp[i]);
		i++;
	}
	return (0);
}
